//Custom script by Zeal & Biscuit

[ComponentEditorProps(category: "Scripts/Game/Gamemode", description: "")]
class SCR_vehicleRespawnComponentClass: ScriptComponentClass{
    
};

class SCR_vehicleRespawnComponent: ScriptComponent{
    
    [Attribute("", UIWidgets.ResourcePickerThumbnail, desc: "Vehicle prefab to spawn (usual the same)",  params: "et")]
    protected ResourceName New_SpawnPrefab;
	
	[Attribute("west_veh_hq", UIWidgets.CheckBox, "Spawn entity's name, at which location the new vehicle should be spawned")];
	protected string Name_SpawnEntity;
  
    [Attribute("1 1 1", UIWidgets.EditBox, "Offset from spawn entity, that new vehicle should be placed")]
    protected vector OffsetSpawnPosition;
   
};

//------------------------------------------------------------------

	//Returns if vehicle is destroyed
	bool ScriptedEntityFilterForQuery(IEntity ent) //IEntity ent wrong?! Need to get owner of component
    {
 		 SCR_VehicleDamageManagerComponent damageManager = SCR_VehicleDamageManagerComponent.Cast(ent.FindComponent(SCR_VehicleDamageManagerComponent));
        
        if (!damageManager) return false; // No vehicle damage manager on entity
        if (!damageManager.IsDestroyed()) return false; // Vehicle is still alive
        return true; // Found what were looking for
    }
    
    //Spawns new vehicle at attributes setup


	//SCR_HintManagerComponent hintComponent = SCR_HintManagerComponent.GetInstance();
	//hintComponent.ShowCustomHint("The vehicle has been destroyed and has been now respawned at its respawn-location", "Vehicle Respawned", 10);