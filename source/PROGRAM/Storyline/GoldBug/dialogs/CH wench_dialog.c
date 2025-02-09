//#include "DIALOGS\Redmond Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
		break;

		case "under_balcony":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "under_balcony1";
		break;

		case "under_balcony1":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "under_balcony2";
		break;

		case "under_balcony2":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "under_balcony3";
		break;

		case "under_balcony3":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("brothel_key");
		break;

		case "on_balcony":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "on_balcony1";
		break;

		case "on_balcony1":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "on_balcony2";
		break;

		case "on_balcony2":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "on_balcony3";
		break;

		case "on_balcony3":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("pistol_package");
		break;

		case "on_balcony_again":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_brothel_balcony");
		break;
	}
}
