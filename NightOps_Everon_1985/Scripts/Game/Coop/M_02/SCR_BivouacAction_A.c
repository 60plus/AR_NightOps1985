class SCR_BivouacAction_A : ScriptedUserAction
{
    void fuckinfuckfuck()
	{
	
	}
	
    override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
    {
        
        auto world = pOwnerEntity.GetWorld();
        auto spawn = world.FindEntityByName("spawnPoint_3");
        auto tent = world.FindEntityByName("bivouac_a_tent_1");
        auto activator = world.FindEntityByName("bivouac_a_activator");
        auto latern = world.FindEntityByName("bivouac_a_crateLantern");
        auto actionsManagerComponent = ActionsManagerComponent.Cast(latern.FindComponent(ActionsManagerComponent));
        //Title Popup
        SCR_PopUpNotification.GetInstance().PopupMsg("1st BIVOUAC ESTABLISHED", duration: 5);
        
        //Spawnpoint Hint
        SCR_HintManagerComponent hintComponent = SCR_HintManagerComponent.GetInstance();
        hintComponent.ShowCustomHint("New spawnpoint at Bivouac available", "SPAWNPOINT UNLOCKED", 10);
        
        //Spawnpoint Unlock
        SCR_SpawnPoint.Cast(spawn).SetFactionKey("US");
        
        //Show Bivouac
		
		
		if(activator)
			Print("We have an activator");
		
		
		auto generic = GenericEntity.Cast(activator);
		
		
		
		if(generic)
			Print("We have an generic");
		
		
		generic.Deactivate();
		
		
		Print("Should be disabled");
		
		
		auto activatorNew = world.FindEntityByName("bivouac_a_activator");
		if(activatorNew)
		{
			Print("Its still accessable");
			
		}else{
			
			Print("Should be good");
		}
		
		
		Print("Setting flag");
		generic.SetFlags(EntityFlags.DISABLED,true);
		
		auto activatorNew2 = world.FindEntityByName("bivouac_a_activator");
		if(activatorNew2)
		{
			Print("Its still accessable");
			
		}else{
			
			Print("Should be good");
		}
		
		
		auto activatorNew3 = world.FindEntityByName("bivouac_a_activator");
		activatorNew3.SendEvent(pOwnerEntity, EntityEvent.DISABLED,fuckinfuckfuck());
	
    }

}