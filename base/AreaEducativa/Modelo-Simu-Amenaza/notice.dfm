object frm: Tfrm
  Left = 291
  Top = 274
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #27880#24847#65306
  ClientHeight = 229
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object mm: TMemo
    Left = 8
    Top = 8
    Width = 439
    Height = 177
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      #20182#30340#25976#25818#24050#34987'Jhonny5'#32129#26550#12290
      #24744#24517#38920#25903#20184'400'#33836#32654#20803#30340#29151#25937#12290
      #23559#37666#23384#20837#20197#19979#24115#25142#65306'XXX'#65292#20195#34920'YYY'#12290
      #23427#26377#26178#38291#21040'2023'#24180'7'#26376'5'#26085#12290
      #25353#25509#21463#25353#37397#38364#38281#31383#21475#12290)
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    OnMouseUp = mmMouseUp
  end
  object ttn: TButton
    Left = 372
    Top = 196
    Width = 75
    Height = 25
    Caption = '&Accept'
    TabOrder = 0
    OnClick = ttnClick
  end
  object mr: TTimer
    Interval = 59998
    OnTimer = mrTimer
    Left = 256
    Top = 208
  end
end
