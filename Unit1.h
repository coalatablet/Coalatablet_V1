//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <System.Sensors.Components.hpp>
#include <System.Sensors.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TListBoxItem *lbLocationSensor;
	TSwitch *swLocationSensorActive;
	TListBoxItem *lbLatitude;
	TListBoxItem *lbLongitude;
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TToolBar *ToolBar1;
	TLabel *Label1;
	TWebBrowser *WebBrowser1;
	TLocationSensor *LocationSensor1;
	TIdTCPClient *IdTCPClient1;
	TTimer *Timer1;
	TTimer *Timer2;
	void __fastcall swLocationSensorActiveSwitch(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
