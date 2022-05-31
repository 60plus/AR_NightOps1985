[EntityEditorProps(category: "GameScripted/ScriptWizard", description: "ScriptWizard generated script file.")]
class SCR_IdentifierComponentClass : ScriptComponentClass
{
}

class SCR_IdentifierComponent : ScriptComponent
{
    [Attribute("", UIWidgets.EditBox, desc: "Add an idetifier here you can later retrieve say in a trigger!", category: "Identifier Component")]
    protected string m_sIdentifier;
    
    string GetIdentifier()
    {
        return m_sIdentifier;
    }
}
