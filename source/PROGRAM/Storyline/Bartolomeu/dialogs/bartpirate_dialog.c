//#include "DIALOGS\Bartpirate_dialog.h"

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
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

                if (PChar.quest.Bartolomeu == "rencontrer")
			{
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin";	
			}
			
			
		break;

               case "begin":

                       NextDiag.CurrentNode = NextDiag.TempNode;
		       DialogExit();
                       AddDialogExitQuest("rencontrebc");
               
                 break;

                       case "begin_1":
       
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[4];
			        link.l1 = DLG_TEXT[5];
			        link.l1.go = "begin_2";

                        break;

                       case "begin_2":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[6];
			        link.l1 = DLG_TEXT[7];
			        link.l1.go = "begin_3";

                        break;

                       case "begin_3":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[8];
			        link.l1 = DLG_TEXT[9];
			        link.l1.go = "exit";
                              AddDialogExitQuest("plage_2");

                        break;

                       case "begin_4":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[10];
			        link.l1 = DLG_TEXT[11];
			        link.l1.go = "exit";
                              PlayStereoSound("VOICE\ENGLISH\Eng_m_c_002.wav");					
                              AddDialogExitQuest("quitterport");

                        break;

                       case "begin_5":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[12];
			        link.l1 = DLG_TEXT[13];
			        link.l1.go = "exit";
                              AddDialogExitQuest("BCstore");

                        break;

                      case "begin_6":
       
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[14];
			        link.l1 = DLG_TEXT[15];
			        link.l1.go = "begin_7";

                        break;

                       case "begin_7":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[16];
			        link.l1 = DLG_TEXT[17];
			        link.l1.go = "begin_8";

                        break;

                       case "begin_8":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[18];
			        link.l1 = DLG_TEXT[19];
			        link.l1.go = "exit";
                              AddDialogExitQuest("fighthubon2");

                        break;

                       case "begin_9":
       
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[20];
			        link.l1 = DLG_TEXT[21];
			        link.l1.go = "begin_10";

                        break;

                       case "begin_10":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[22];
			        link.l1 = DLG_TEXT[23];
			        link.l1.go = "begin_11";

                        break;

                       case "begin_11":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[24];
			        link.l1 = DLG_TEXT[25];
			        link.l1.go = "begin_12";
                             

                        break;

                       case "begin_12":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[26];
			        link.l1 = DLG_TEXT[27];
			        link.l1.go = "begin_13";
                              

                        break;

                       case "begin_13":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[28];
			        link.l1 = DLG_TEXT[29];
			        link.l1.go = "exit";
                              AddDialogExitQuest("finbathub2");

                        break;


               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                 break;


	}
}
