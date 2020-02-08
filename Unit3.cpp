//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
String r;
int i=0, j=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    r=DBGrid1->Fields[i]->Text;
	ShowMessage(DBGrid1->Fields[i]->Text);
	StringGrid1->Cells[i][j]=r;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ADOQuery1->Next();
	j++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	i++;

	if(i==4)
		i=0;
	Edit2->Text=i;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from std where std_name like '%"+Edit1->Text+"%'");
	ADOQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket)

{

	String data, data_protocol, DBdata;
	int n=0;
	int count=0;

	data=Socket->ReceiveText();
	data_protocol=data.SubString(1,2);

	if(data_protocol=="T@")
	{
		ShowMessage(data);

        ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("select * from std where std_name like '%"+data+"%'");
		ADOQuery1->Open();

		count=DBGrid1->Fields[0]->DataSet->RecordCount;

		for(i=0; i<count; i++)
		{
			DBdata=DBGrid1->Fields[n]->Text;
			//ShowMessage("test:"+DBdata);
			ServerSocket1->Socket->Connections[0]->SendText("T@"+DBdata);
			n++;
			i--;

			if(n==4)
			{
				n=0;
				ADOQuery1->Next();
				i++;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
    ShowMessage("Conneted");
}
//---------------------------------------------------------------------------

