[EntityEditorProps(category: "GameScripted/Coop", description: "ScriptWizard generated script file.")]
class SCR_EntityShowClass : ScriptComponentClass
{
}

class SCR_EntityShow : ScriptComponent
{
    [Attribute("", UIWidgets.Auto, "StaticModelEntity to show", category: "Show Static ModelEntities")]
    protected ref array<string> m_StaticModelEntity;
	
	[Attribute("", UIWidgets.Auto, "GenericEntity to show", category: "Show Generic Entities")]
    protected ref array<string> m_GenericEntity;
	
	[Attribute("", UIWidgets.Auto, "GameEntity to show", category: "Show Game Entities")]
    protected ref array<string> m_GameEntity;
	
	[Attribute("", UIWidgets.Auto, "Vehicle to show", category: "Show Vehicle Entities")]
    protected ref array<string> m_VehicleEntity;
    
    protected SCR_BaseTriggerEntity m_pActivationTrigger;
    
    override void OnPostInit(IEntity owner)
    {
        super.OnPostInit(owner);
        SetEventMask(owner, EntityEvent.INIT);
    }
    
    
      override void EOnInit(IEntity owner)
    {
        if (!GetGame().InPlayMode())
            return;
        
        m_pActivationTrigger = SCR_BaseTriggerEntity.Cast(owner);
        
        if (!m_pActivationTrigger)
        {
            Print("SCR_GroupActivator cannot hook to trigger, maybe check the supplied name!");
            return;
        }
        
        m_pActivationTrigger.GetOnActivate().Insert(OnTriggerActivate);
    }
    
    protected void OnTriggerActivate()
    {
        
        //Show StaticModelEntities
        foreach (string staticEntityName : m_StaticModelEntity)
        {
            StaticModelEntity entity = StaticModelEntity.Cast(GetGame().GetWorld().FindEntityByName(staticEntityName));
            
            if (entity)
                entity.Show(true);
        }
		
		//Show GenericEntities
        foreach (string genericEntityName : m_GenericEntity)
        {
            GenericEntity entity = GenericEntity.Cast(GetGame().GetWorld().FindEntityByName(genericEntityName));
            
            if (entity)
                entity.Show(true);
        }
		
		//Show GameEntities
        foreach (string gameEntityName : m_GameEntity)
        {
            GameEntity entity = GameEntity.Cast(GetGame().GetWorld().FindEntityByName(gameEntityName));
            
            if (entity)
                entity.Show(true);
        }
		
		//Show VehicleEntities
        foreach (string vehicleEntityName : m_VehicleEntity)
        {
            Vehicle entity = Vehicle.Cast(GetGame().GetWorld().FindEntityByName(vehicleEntityName));
            
            if (entity)
                entity.Show(true);
			    //entity.Disabled(false);
        }
        
      TriggerUnsubscribe();
    }
    
    protected void TriggerUnsubscribe()
    {
        if (!m_pActivationTrigger)
            m_pActivationTrigger.GetOnActivate().Remove(OnTriggerActivate);
    }
    
    override void OnDelete(IEntity owner)
    {
        if (!GetGame().InPlayMode())
            return;
        
        TriggerUnsubscribe();
    }
}