[EntityEditorProps(category: "Scripts/Game/Gamemode", description: "")]
class SCR_AttachedSpawnpointClass: SCR_BasePrefabSpawnerClass
{

};

class SCR_AttachedSpawnpoint: SCR_BasePrefabSpawner{

    [Attribute("0", UIWidgets.CheckBox, "Should the prefab spawn on start")];
    bool spawnAtStart;

    [Attribute("0", UIWidgets.CheckBox, "MHQ Faction")];
    protected string factionKey;

    protected Vehicle vehicle;

    protected SCR_SpawnPoint spawnpoint;
    override void EOnInit(IEntity owner){
        vehicle = Vehicle.Cast(this.GetParent());
        spawnpoint = SCR_SpawnPoint.Cast(this.GetChildren());

        Print(vehicle);
        Print(spawnpoint);
        if(spawnAtStart){
            spawnpoint.SetFactionKey(factionKey);
        }else{
            spawnpoint.SetFactionKey("Inactive");
        }
    }
    void toggleAttachedSpawnpointState(){
        string keyState = spawnpoint.GetFactionKey();
        if(keyState == "Inactive"){
            spawnpoint.SetFactionKey(factionKey);
        }else{
            spawnpoint.SetFactionKey("Inactive");
        }
    }

    string getFactionKey(){
        return factionKey;
    }

};