object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 409
  ClientWidth = 691
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 159
    Top = 139
    Width = 37
    Height = 13
    Caption = 'SQL like'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 353
    Height = 121
    DataSource = DataSource1
    Options = [dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Button2: TButton
    Left = 487
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Next'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 487
    Top = 199
    Width = 75
    Height = 25
    Caption = 'Right'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button1: TButton
    Left = 487
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 143
    Top = 158
    Width = 75
    Height = 21
    TabOrder = 4
    OnChange = Edit1Change
  end
  object StringGrid1: TStringGrid
    Left = 383
    Top = 8
    Width = 281
    Height = 121
    TabOrder = 5
    RowHeights = (
      24
      23
      24
      24
      24)
  end
  object Edit2: TEdit
    Left = 487
    Top = 231
    Width = 75
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object ServerSocket1: TServerSocket
    Active = True
    Port = 100
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientRead = ServerSocket1ClientRead
    Left = 280
    Top = 200
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Se' +
      'rver\mdb\SLAB.mdb;Mode=Share Deny None;Persist Security Info=Fal' +
      'se;Jet OLEDB:System database="";Jet OLEDB:Registry Path="";Jet O' +
      'LEDB:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Data' +
      'base Locking Mode=0;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLED' +
      'B:Global Bulk Transactions=1;Jet OLEDB:New Database Password="";' +
      'Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Databas' +
      'e=False;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:C' +
      'ompact Without Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 136
    Top = 200
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from std')
    Left = 64
    Top = 200
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 208
    Top = 200
  end
end
