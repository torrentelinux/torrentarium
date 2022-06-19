object DlgAjustes: TDlgAjustes
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Ajustes'
  ClientHeight = 139
  ClientWidth = 384
  Color = clBtnFace
  CustomTitleBar.CaptionAlignment = taCenter
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 281
    Height = 97
    Shape = bsFrame
  end
  object OKBtn: TButton
    Left = 301
    Top = 50
    Width = 75
    Height = 25
    Hint = 'Aceptar|Acepta los datos ingresados.'
    Caption = 'Aceptar'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 301
    Top = 80
    Width = 75
    Height = 25
    Hint = 'Cancelar|Cancela la entrada de datos.'
    Cancel = True
    Caption = 'Cancelar'
    ModalResult = 2
    TabOrder = 3
    OnClick = CancelBtnClick
  end
  object meDirIP: TMaskEdit
    Left = 80
    Top = 16
    Width = 100
    Height = 24
    Hint = 
      'Ponga aqu'#237' la dir. IPv4.|Por ejemplo: 142.251.133.46 [ESC] borra' +
      ' contenido.'
    EditMask = '!099.099.099.099;1;_'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 15
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = '   .   .   .   '
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 16
    Width = 17
    Height = 20
    Caption = 'IP'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object StaticText2: TStaticText
    Left = 16
    Top = 56
    Width = 48
    Height = 20
    Caption = 'Puerto'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object mePuerto: TMaskEdit
    Left = 80
    Top = 56
    Width = 44
    Height = 21
    Hint = 
      'Ponga aqu'#237' el n'#186' de puerto TCP.|Por ejemplo: 123. [ESC] Borra co' +
      'ntenido.'
    EditMask = '!99999;1;_'
    MaxLength = 5
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    Text = '     '
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 120
    Width = 384
    Height = 19
    AutoHint = True
    Panels = <>
    ParentShowHint = False
    ShowHint = False
    SimplePanel = True
  end
  object btnBorrar: TButton
    Left = 301
    Top = 8
    Width = 75
    Height = 25
    Hint = 'Borrar|Borra IP y Puerto.'
    Caption = 'Borrar'
    TabOrder = 7
    OnClick = btnBorrarClick
  end
end
