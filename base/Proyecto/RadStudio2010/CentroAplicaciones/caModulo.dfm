object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Hint = 'Doble click muestra la ayuda.'
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Centro de aplicaciones'
  ClientHeight = 359
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  ShowHint = True
  OnClick = FormClick
  OnDblClick = FormDblClick
  PixelsPerInch = 96
  TextHeight = 13
  object lblAplic1: TLabel
    Left = 24
    Top = 40
    Width = 161
    Height = 25
    Hint = 'Inicia la instalaci'#243'n de Java JDK 32/64 bits.'
    AutoSize = False
    Caption = 'Oracle Java JDK 8'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    Transparent = True
    OnClick = lblAplic1Click
    OnMouseEnter = lblAplic1MouseEnter
    OnMouseLeave = lblAplic1MouseLeave
  end
  object lblAplic2: TLabel
    Left = 24
    Top = 71
    Width = 161
    Height = 25
    Hint = 'Inicia la instalaci'#243'n de JDeveloper 32/64 bits.'
    AutoSize = False
    Caption = 'Oracle JDeveloper'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    Transparent = True
    OnClick = lblAplic2Click
    OnMouseEnter = lblAplic2MouseEnter
    OnMouseLeave = lblAplic2MouseLeave
  end
  object lblPath: TLabel
    Left = 24
    Top = 145
    Width = 161
    Height = 17
    Hint = 'Ajusta la variable del Sistema.'
    AutoSize = False
    Caption = 'Ajustar PATH'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsUnderline]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = lblPathClick
    OnMouseEnter = lblPathMouseEnter
    OnMouseLeave = lblPathMouseLeave
  end
  object lblJava: TLabel
    Left = 24
    Top = 254
    Width = 161
    Height = 18
    Hint = 'Visite en internet el sitio de Java Oficial.'
    AutoSize = False
    Caption = 'Java.com'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = lblJavaClick
    OnMouseEnter = lblJavaMouseEnter
    OnMouseLeave = lblJavaMouseLeave
  end
  object lblRevisarPath: TLabel
    Left = 24
    Top = 169
    Width = 161
    Height = 25
    AutoSize = False
    Caption = 'Revisar PATH'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = lblRevisarPathClick
    OnMouseEnter = lblRevisarPathMouseEnter
    OnMouseLeave = lblRevisarPathMouseLeave
  end
  object Bevel1: TBevel
    Left = 207
    Top = 8
    Width = 14
    Height = 273
    Shape = bsLeftLine
  end
  object txtEncabezado: TStaticText
    Left = 8
    Top = 17
    Width = 193
    Height = 17
    AutoSize = False
    Caption = 'Instalar aplicaci'#243'n _____________'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object grpBotones: TButtonGroup
    Left = 232
    Top = 0
    Width = 215
    Height = 54
    BorderWidth = 1
    ButtonWidth = 62
    ButtonOptions = [gboAllowReorder, gboFullSize, gboGroupStyle, gboShowCaptions]
    Items = <
      item
        Caption = 'Configurar Java'
        Hint = 'Selecciona la ubicaci'#243'n del archivo.'
        OnClick = ButtonGroup1Items0Click
      end
      item
        Caption = 'Configurar JDeveloper'
        Hint = 'Selecciona la ubicaci'#243'n del archivo.'
        OnClick = grpBotonesItems1Click
      end
      item
        Caption = 'Salir'
        Hint = 'Termina la aplicaci'#243'n.'
        OnClick = ButtonGroup1Items1Click
      end>
    TabOrder = 1
  end
  object txtVarsEntorno: TStaticText
    Left = 8
    Top = 115
    Width = 193
    Height = 17
    AutoSize = False
    Caption = 'Variables de entorno __________'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object sbBarraDeEstado: TStatusBar
    Left = 0
    Top = 340
    Width = 455
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Ok.'
  end
  object mmAyuda: TMemo
    Left = 224
    Top = 60
    Width = 223
    Height = 205
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      '         <Descripci'#243'n>'
      'Centro de aplicaciones para productos Oracle.'
      'Utilitario para realizar instalaciones con ficheros .zip'
      'Dirigido para aquellos usuarios programadores y'
      'desarrolladores en lenguaje Java con nivel inicial a intermedio.'
      'Para conocer qu'#233' es la variable de entorno PATH, visite'
      'el sitio https://www.java.com/es/download/help/path.html'
      '*___'
      
        'Aplicaci'#243'n de 32 bits para Windows Vista y versiones posteriores' +
        '.'
      'Desarrollado por Eugenio Mart'#237'nez.'
      '____*')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 4
    WantTabs = True
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 223
    Width = 177
    Height = 18
    AutoSize = False
    Caption = 'Mundo Java ___________'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object dlgAbrirFichero: TFileOpenDialog
    DefaultExtension = '.exe'
    DefaultFolder = 'c:\\'
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'Ejecutable'
        FileMask = '*.exe'
      end
      item
        DisplayName = 'Comprimido'
        FileMask = '*.zip'
      end
      item
        DisplayName = 'Todos'
        FileMask = '*.*'
      end>
    Options = []
    Title = 'Ubicaci'#243'n de instalador'
    Left = 224
    Top = 280
  end
  object dlgAbrirDir: TFileOpenDialog
    DefaultFolder = 'c:\'
    FavoriteLinks = <>
    FileName = 'c:\Oracle\Middleware\Oracle_Home'
    FileTypes = <>
    FileTypeIndex = 0
    OkButtonLabel = 'Seleccione carpeta'
    Options = [fdoPickFolders, fdoHideMRUPlaces, fdoNoDereferenceLinks, fdoDontAddToRecent, fdoDefaultNoMiniMode]
    Title = 'Seleccione directorio destino'
    Left = 152
    Top = 280
  end
end
