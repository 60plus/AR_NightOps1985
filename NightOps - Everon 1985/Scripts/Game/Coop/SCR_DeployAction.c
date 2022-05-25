//Script by Joe Malley to deploy or undeploy a vehicle unlocking a respawn PrefabGeneratorAssetPoint
//Modified and simplified by Zeal

class SCR_DeployAction : ScriptedUserAction
{
	bool stateM = false;
	
	override event bool GetActionNameScript(out string outName){

		if(!stateM){
			outName = "Deploy Spawnpoint (Blocks Vehicle)" ;
		}else{
			outName = "Undeploy Spawnpoint (Release Vehicle)" ;
		}
		return true;
		//return false; 
	};
	override event bool GetActionDescriptionScript(out string outName) { 
		if(!stateM){
			outName = "(Removes Fuel)" ;
		}else{
			outName = "(Returns Fuel)" ;
		}
		return true;
	};
	override event void Init(IEntity pOwnerEntity, GenericComponent pManagerComponent){
		stateM = false;
	}
	override event void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity){
		stateM = SCR_DeployVehicleComponent.Cast(pOwnerEntity.FindComponent(SCR_DeployVehicleComponent)).toggleDeployState(!stateM);
		
	}
};