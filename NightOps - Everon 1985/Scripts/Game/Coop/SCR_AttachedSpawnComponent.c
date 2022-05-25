//Custom script by Zeal
//Based on prefab by Joe Malley

[ComponentEditorProps(category: "Scripts/Game/Gamemode", description: "")]
class SCR_AttachedSpawnComponentClass: ScriptComponentClass{
    
};

class SCR_AttachedSpawnComponent: ScriptComponent{
    
    [Attribute("0", UIWidgets.CheckBox, "Should the prefab spawn on start")];
    bool spawnAtStart;
    
    [Attribute("0", UIWidgets.CheckBox, "Faction")];
    protected string factionKey;
    
    [Attribute("", UIWidgets.ResourcePickerThumbnail, desc: "Spawnpoint prefab to use",  params: "et")]
    protected ResourceName m_rnPrefab;
    
    [Attribute("", UIWidgets.EditBox, "Offset from vehicle origin, that spawn should be placed")]
    protected vector m_vSpawnPosition;
    
    protected SCR_SpawnPoint spawnpoint;
    void Setup(IEntity owner){
        this.spawnpoint = createSpawnPoint();

        if(spawnAtStart){
            spawnpoint.SetFactionKey(factionKey);
        }else{
            spawnpoint.SetFactionKey("Inactive");
        }
    }
    bool toggleAttachedSpawnpoint(bool state){

        
        if(state == true){
            this.spawnpoint = createSpawnPoint();
			
			//GetOwner().AddChild(spawnpoint, 0);
			
			
			
            return true;
        }else{
            RplComponent.DeleteRplEntity(this.spawnpoint, false);
            return false;
        }
    }
	 string getFactionKey(){
        return factionKey;
    }
    
    SCR_SpawnPoint createSpawnPoint(){
        
        BaseWorld myWorld = GetOwner().GetWorld();
        if (!myWorld || m_rnPrefab.IsEmpty())
            return null;
        
        Resource res = Resource.Load(m_rnPrefab);
        EntitySpawnParams params();
		
		//params.Parent = GetOwner(); //Makes a spawnpoint child of the parent vehicle
        
        vector mat[4];
        GetOwner().GetWorldTransform(mat);
        mat[3] = mat[3] + m_vSpawnPosition;
        params.Transform = mat;
        IEntity newEnt = GetGame().SpawnEntityPrefab(res, myWorld, params);
        if (!newEnt)
            return null;
        newEnt.SetFlags(EntityFlags.VISIBLE, true);
        
        return SCR_SpawnPoint.Cast(newEnt);
    }
};