//Custom script by Zeal & Biscuit

[EntityEditorProps(category: "GameScripted/ScriptWizard", description: "ScriptWizard generated script file.")]
class SCR_VehicleRespawnerClass : GenericEntityClass
{
}
 
class SCR_VehicleRespawner : GenericEntity
{
    [Attribute("", UIWidgets.ResourcePickerThumbnail, desc: "Vehicle prefab to spawn (usual the same)",  params: "et")]
    protected ResourceName m_rnSpawnPrefab;
    
    [Attribute("", UIWidgets.EditBox, "Spawn entity's name, at which location the new vehicle should be spawned")];
    protected string m_sSpawnLocationEntityName;
	
	//Attribute for respawn timer needed
  
	//To be removed
    [Attribute("0 0 0", UIWidgets.EditBox, "Offset from spawn entity, that new vehicle should be placed")]
    protected vector m_vOffsetSpawnPosition;
	
	//To be removed
	[Attribute("1", UIWidgets.CheckBox, "Should the player get a hint notification on respawn?")];
	bool showHint;
 
    protected IEntity m_pEntityToSpawnAt;
    protected IEntity m_pLastSpawnedVehicle;
    
    override void EOnInit(IEntity owner)
    {
        if (!GetGame().InPlayMode())
            return;
 
        GetGame().GetCallqueue().CallLater(QueryLater, 0);
    }
    
    void QueryLater()
    {
        m_pEntityToSpawnAt = GetGame().GetWorld().FindEntityByName(m_sSpawnLocationEntityName);
        if (!m_pEntityToSpawnAt)
            return;
        
        SpawnVehicle();
    }
    
    protected bool TryRegister(IEntity targetEntity)
    {
        EventHandlerManagerComponent eventHandlerManager = EventHandlerManagerComponent.Cast(targetEntity.FindComponent(EventHandlerManagerComponent));
        if (eventHandlerManager)
        {
            eventHandlerManager.RegisterScriptHandler("OnDestroyed", targetEntity, OnVehicleDeystroyed);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    protected bool TryUnregister(IEntity targetEntity)
    {
        EventHandlerManagerComponent eventHandlerManager = EventHandlerManagerComponent.Cast(targetEntity.FindComponent(EventHandlerManagerComponent));
        if (eventHandlerManager)
        {
            eventHandlerManager.RemoveScriptHandler("OnDestroyed", targetEntity, OnVehicleDeystroyed);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void OnVehicleDeystroyed(IEntity targetEntity)
    {
        if (m_pLastSpawnedVehicle)
            TryUnregister(m_pLastSpawnedVehicle);
        
        SpawnVehicle();
    }
    
    protected void SpawnVehicle()
    {
	
        Resource prefab = Resource.Load(m_rnSpawnPrefab);
        if (!prefab)
        {
            Print(string.Format("SCR_VehicleRespawnComponent could not load '%1'", prefab));
            return;
        }
        
        EntitySpawnParams spawnParams = new EntitySpawnParams();
        spawnParams.TransformMode = ETransformMode.WORLD;
		
		//Needs an overhaul
		vector mat[4];
     	GetWorldTransform(mat);
        mat[3] = mat[3] + m_vOffsetSpawnPosition;
        GetSpawnTransform(spawnParams.Transform);
		spawnParams.Transform = mat;
 
        IEntity spawnedVehicle = GetGame().SpawnEntityPrefab(prefab, GetGame().GetWorld(), spawnParams);
        if (!spawnedVehicle)
        {
            Print(string.Format("SCR_VehicleRespawnComponent could not spawn '%1'", prefab));
            return;
        }
        
        TryRegister(spawnedVehicle);
		
		if (showHint)
		{
			SCR_HintManagerComponent hintComponent = SCR_HintManagerComponent.GetInstance();
			hintComponent.ShowCustomHint("The vehicle has been destroyed and is now respawning...", "Vehicle Respawned", 10);
		}
	} 
    
    protected void GetSpawnTransform(out vector transformMatrix[4])
    {
		
        vector rotation = vector.Zero;
        vector yawPitchRoll = Vector(rotation[1], rotation[0], rotation[2]);
        Math3D.AnglesToMatrix(rotation, transformMatrix);       
        transformMatrix[3] = m_pEntityToSpawnAt.GetOrigin();
    }
 
    void SCR_VehicleRespawner(IEntitySource src, IEntity parent)
    {
        SetEventMask(EntityEvent.INIT);
    }
    
    void ~SCR_VehicleRespawner()
    {
    }
 
}