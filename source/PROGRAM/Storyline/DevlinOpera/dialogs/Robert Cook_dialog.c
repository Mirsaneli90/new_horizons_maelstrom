void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("Armada_contract", "open"))			
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Island_stuff";
			}
			if (checkquestattribute("Bonnie_talk", "Hunting_for_Blaze") && checkquestattribute("Chosen_Quest", "Robert_Cook"))
			{
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];			
				link.l1.go = "Exit";
			}			
			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("Armada_contract", "sealed"))
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];			
				link.l1.go = "Island_stuff3";			
			}
		break;

		case "Island_stuff":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_for_choice";
		break;

		case "Island_stuff3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Island_stuff4";
		break;
		
		case "Island_stuff4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Island_stuff5";
		break;

		case "Island_stuff5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Island_stuff6";
		break;
		
		case "Island_stuff6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Island_stuff7";
		break;		

		case "Island_stuff7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Island_stuff8";
		break;

		case "Island_stuff8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Island_stuff";
		break;
	
		case "Exit_Island_stuff":
			pchar.quest.Mings_contract = "done";
			pchar.quest.Catalina_contract = "done";
			pchar.quest.CCC_contract = "done";
			pchar.quest.Armada_contract = "done";
			pchar.quest.Bonnie_talk = "Needing_family_help";
			pchar.quest.Chosen_Quest = "Robert_Cook";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Moving_right_along");
		break;

		case "Exit_for_choice":
			pchar.quest.Armada_contract = "sealed";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
