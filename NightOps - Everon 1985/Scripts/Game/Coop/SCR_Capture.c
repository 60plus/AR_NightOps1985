class SCR_CaptureVehicle : ScriptedUserAction
{
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		SCR_PopUpNotification.GetInstance().PopupMsg("RADIO TRUCK CAPTURED");
		
		 SCR_BaseGameMode gameMode = SCR_BaseGameMode.Cast(GetGame().GetGameMode()); // Get the game mode for the end script
        Faction faction = GetGame().GetFactionManager().GetFactionByKey("US"); // Get the winning faction Key
        int usIndex = GetGame().GetFactionManager().GetFactionIndex(faction); // Get the winning faction key's index
        gameMode.EndGameMode(SCR_GameModeEndData.CreateSimple(SCR_GameModeEndData.ENDREASON_EDITOR_FACTION_VICTORY, -1, usIndex)); // End the mission!
	}

}