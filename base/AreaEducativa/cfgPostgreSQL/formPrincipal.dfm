object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Configuraci'#243'n - PostgreSQL -'
  ClientHeight = 451
  ClientWidth = 379
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  ShowHint = True
  PixelsPerInch = 96
  TextHeight = 13
  object btnCerrar: TButton
    Left = 296
    Top = 401
    Width = 75
    Height = 25
    Caption = '&Cerrar'
    TabOrder = 0
    OnClick = btnCerrarClick
  end
  object stbEstado: TStatusBar
    Left = 0
    Top = 432
    Width = 379
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Opciones.'
  end
  object PageControlPrincipal: TPageControl
    Left = 8
    Top = 16
    Width = 360
    Height = 233
    ActivePage = Hoja1
    TabOrder = 2
    object Hoja1: TTabSheet
      Caption = 'General'
      object Label1: TLabel
        Left = 4
        Top = 44
        Width = 32
        Height = 18
        AutoSize = False
        Caption = 'port'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 4
        Top = 76
        Width = 104
        Height = 18
        AutoSize = False
        Caption = 'max_connections'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 4
        Top = 106
        Width = 104
        Height = 18
        AutoSize = False
        Caption = 'shared_buffers'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object StaticText3: TStaticText
        Left = 4
        Top = 16
        Width = 102
        Height = 17
        AutoSize = False
        Caption = 'listen_addresses'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object edtListenAddr: TEdit
        Left = 112
        Top = 16
        Width = 226
        Height = 21
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object edtPort: TEdit
        Left = 112
        Top = 43
        Width = 104
        Height = 24
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object edtMaxConn: TEdit
        Left = 112
        Top = 73
        Width = 104
        Height = 24
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object edtShareBuff: TEdit
        Left = 112
        Top = 105
        Width = 104
        Height = 24
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
    end
    object Hoja2: TTabSheet
      Caption = 'Avanzado'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
    object Hoja3: TTabSheet
      Caption = 'Extras'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
    object Hoja4: TTabSheet
      Caption = 'Opciones'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object StaticText1: TStaticText
        Left = 4
        Top = 24
        Width = 167
        Height = 20
        Caption = 'Ubicaci'#243'n de postgresql.conf'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object StaticText2: TStaticText
        Left = 3
        Top = 77
        Width = 150
        Height = 20
        Caption = 'Ubicaci'#243'n de pg_hba.conf'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object btnSeleccionar1: TButton
        Left = 274
        Top = 46
        Width = 75
        Height = 25
        Caption = 'Seleccionar'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = btnSeleccionar1Click
      end
      object edtLinea1: TEdit
        Left = 3
        Top = 50
        Width = 258
        Height = 22
        AutoSize = False
        TabOrder = 3
        Text = 'postgresql.conf'
      end
      object edtLinea2: TEdit
        Left = 3
        Top = 103
        Width = 258
        Height = 21
        TabOrder = 4
        Text = 'pg_hba.conf'
      end
      object btnSeleccionar2: TButton
        Left = 274
        Top = 101
        Width = 75
        Height = 25
        Caption = 'Seleccionar'
        TabOrder = 5
        OnClick = btnSeleccionar2Click
      end
    end
    object Hoja5: TTabSheet
      Caption = 'Ayuda'
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
  end
  object mmMensajes: TMemo
    Left = 8
    Top = 264
    Width = 360
    Height = 129
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'Mensajes...')
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
  end
  object btnAyuda: TButton
    Left = 208
    Top = 401
    Width = 75
    Height = 25
    Caption = 'Ayuda'
    TabOrder = 4
    OnClick = btnAyudaClick
  end
  object dlgAbrirConfig: TOpenTextFileDialog
    FileName = 'postgresql.conf'
    InitialDir = '%USERPROFILE%'
    Title = 'Abrir postgresql.conf'
    Left = 48
    Top = 368
  end
end
