[EntityEditorProps(category: "Scripts/Game/Gamemode", description: "")]

class SCR_WorldPrefabSpawnerClass: SCR_BasePrefabSpawnerClass
{

};

class SCR_WorldPrefabSpawner: SCR_BasePrefabSpawner{

	override void EOnInit(IEntity owner) {}
	
	void callParentSpawn(){
			super.Spawn();
	}
	
	

	
};