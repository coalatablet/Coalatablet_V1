//---------------------------------------------------------------------------

#include <fmx.h>
#include <stdlib.h>
#include <Androidapi.Helpers.hpp>
#include <Androidapi.JNI.Net.hpp>
#include <FMX.DialogService.hpp>
#include <System.Permissions.hpp>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
String lat, longi;
String latitude, longitude;
float latitudea, latitudeo, longitudea, longitudeo;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::swLocationSensorActiveSwitch(TObject *Sender)
{
#ifdef __ANDROID__
	DynamicArray<String> permissions;
	permissions.Length = 1;
	permissions[0] = "android.permission.ACCESS_FINE_LOCATION";

	PermissionsService()->RequestPermissions(permissions,
		[this](const DynamicArray<String> APermissions, const DynamicArray<TPermissionStatus> AGrantResults)
		{
			if ((AGrantResults.Length == 1) && (AGrantResults[0] == TPermissionStatus::Granted))
			{
				// activate or deactivate the location sensor
				LocationSensor1->Active = swLocationSensorActive->IsChecked;
			}
			else
			{
				this->swLocationSensorActive->IsChecked = false;

				TDialogService::ShowMessage("Location permission not granted");
			}
		});
#else
	LocationSensor1->Active = swLocationSensorActive->IsChecked;
#endif
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=true;
	IdTCPClient1->Host=Edit1->Text;
	IdTCPClient1->Connect();
	if(IdTCPClient1->Connected())
	{
		ShowMessage("Connected");
	}
	else
	{
		ShowMessage("Failed");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	latitudeo = 37.49964;
	longitudeo = 127.06360;
	latitudea = StrToFloat(latitude); //현위치
	longitudea = StrToFloat(longitude); //현위치
			if(latitudeo-0.00004 <= latitudea && latitudea<=latitudeo+0.00004&&longitudeo-0.00004<=longitudea&&longitudea<=longitudeo+0.00004) //비교
			{
			while(1)
			{
					_di_JObject obj=SharedActivityContext()->getSystemService(TJContext::JavaClass->VIBRATOR_SERVICE);
					_di_JVibrator vibrator = TJVibrator::Wrap(((_di_ILocalObject)obj)->GetObjectID());
					vibrator->vibrate(1000);
			if(latitudeo-0.00004 <= latitudea && latitudea<=latitudeo+0.00004&&longitudeo-0.00004<=longitudea&&longitudea<=longitudeo+0.00004) //비교
				{
					break;
				}
			}
			}
			else
			{
			}
/*
int i;
	int bufsize;
	UnicodeString receive;
	if(IdTCPClient1->Connected())
	{
		if(!IdTCPClient1->IOHandler->InputBufferIsEmpty())
		{
			bufsize=IdTCPClient1->IOHandler->InputBuffer->Size;
			receive=IdTCPClient1->IOHandler->ReadString(bufsize,IndyTextEncoding(949));
			i=receive.Pos("@");
			lat=receive.SubString(0,i);
			longi=receive.Delete(0,i+1);
			latitudea = StrToFloat(latitude); //현위치
			longitudea = StrToFloat(longitude); //현위치
			latitudeo = StrToFloat(lat); //받은위치
			longitudeo = StrToFloat(longi); //받은위치

			if(latitudeo-100 <= latitudea && latitudea<=latitudeo+100&&longitudeo-100<=longitudea&&longitudea<=longitudeo+100) //비교
			{
			ShowMessage("Same");
			while(1)
			{
					_di_JObject obj=SharedActivityContext()->getSystemService(TJContext::JavaClass->VIBRATOR_SERVICE);
					_di_JVibrator vibrator = TJVibrator::Wrap(((_di_ILocalObject)obj)->GetObjectID());
					vibrator->vibrate(1000);
			if(latitudeo-100 <= latitudea && latitudea<=latitudeo+100&&longitudeo-100<=longitudea&&longitudea<=longitudeo+100) //비교
				{
					break;
				}
			}
			}
			else
			{
				ShowMessage("Not Same");
			}
		}
	}
	*/
	}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
latitude = String().sprintf(L"%2.5f", NewLocation.Latitude);
	longitude = String().sprintf(L"%2.5f", NewLocation.Longitude);

	// convert the location to latitude and longitude
	lbLatitude->Text = latitude;
	lbLongitude->Text = longitude;

	TVarRec params[] = { lbLatitude->Text, lbLongitude->Text };

	// and track the location via Google Maps
	WebBrowser1->Navigate(Format("https://maps.google.com/maps?q=%s,%s", params, 2));
	if(IdTCPClient1->Connected())
	{
		IdTCPClient1->Socket->Write("@", IndyTextEncoding(949));
	}
}
//---------------------------------------------------------------------------

