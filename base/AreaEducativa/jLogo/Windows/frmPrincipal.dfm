object frmCentral: TfrmCentral
  Left = 0
  Top = 0
  Caption = 'JLogo'
  ClientHeight = 392
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  PopupMenu = mnuEmergente
  PopupMode = pmAuto
  WindowState = wsMaximized
  OnClick = FormClick
  OnKeyPress = FormKeyPress
  TextHeight = 17
  object lblAviso: TLabel
    Left = 80
    Top = 100
    Width = 469
    Height = 17
    Caption = 
      'Presione una tecla cualquiera del teclado/rat'#243'n para visualizar ' +
      'la hoja de dibujo.'
  end
  object rtfEdit: TRichEdit
    Left = 8
    Top = 216
    Width = 180
    Height = 89
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Lucida Console'
    Font.Style = []
    HideScrollBars = False
    Lines.Strings = (
      'rtfEdit')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    Visible = False
  end
  object sbBarraEstado: TStatusBar
    Left = 0
    Top = 373
    Width = 628
    Height = 19
    Panels = <
      item
        Text = 'Panel 1'
        Width = 180
      end
      item
        Text = 'Panel 2'
        Width = 150
      end
      item
        Text = 'Panel 3'
        Width = 150
      end>
    ExplicitTop = 372
    ExplicitWidth = 624
  end
  object mnuEmergente: TPopupMenu
    Left = 368
    Top = 184
    object opcAcercaDe: TMenuItem
      Caption = 'Acerca De...'
      OnClick = opcAcercaDeClick
    end
    object opcSalir: TMenuItem
      Caption = 'Salir'
      OnClick = opcSalirClick
    end
  end
end
