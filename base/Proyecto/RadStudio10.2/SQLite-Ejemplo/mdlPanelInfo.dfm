inherited dlgPanelInfo: TdlgPanelInfo
  BorderStyle = bsToolWindow
  Caption = 'Panel informativo'
  ClientHeight = 254
  ClientWidth = 409
  KeyPreview = True
  PopupMode = pmAuto
  ExplicitWidth = 415
  ExplicitHeight = 278
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel1: TBevel
    Width = 308
    Height = 234
    Style = bsRaised
    ExplicitWidth = 308
    ExplicitHeight = 234
  end
  inherited OKBtn: TButton
    Left = 326
    Caption = '&Aceptar'
    ExplicitLeft = 326
  end
  inherited CancelBtn: TButton
    Left = 326
    Caption = '&Cancelar'
    Visible = False
    ExplicitLeft = 326
  end
  object mmAyuda: TMemo
    Left = 8
    Top = 10
    Width = 306
    Height = 231
    Color = clInfoBk
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'SQLite_Ejemplo v1.0 * Marzo de 2024'
      ''
      'Esta aplicaci'#243'n hace uso de SQLite para el acceso '
      'a las bases de datos .sdb sin modificar sus datos.'
      'El archivo .sdb puede estar almacenado en un'
      'dispositivo local o remoto.'
      'Presione las teclas Ctrl+S para seleccionar y'
      'abrir el archivo .sdb.'
      'Puede hacer clic derecho del rat'#243'n sobre la'
      'superficie de la ventana para visualizar el men'#250
      'contextual de la aplicaci'#243'n.'
      'Tambi'#233'n puede presionar la tecla Men'#250' que est'#225
      'a su derecha del teclado para que aparezca el'
      'men'#250' de opciones de la aplicaci'#243'n.')
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
end
