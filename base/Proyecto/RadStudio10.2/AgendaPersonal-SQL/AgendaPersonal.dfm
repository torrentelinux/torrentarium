object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Agenda Personal'
  ClientHeight = 478
  ClientWidth = 1015
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClick = FormClick
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object sbtnGrilla: TSpeedButton
    Left = 288
    Top = 35
    Width = 23
    Height = 25
    Hint = 'Ocultar planilla.'
    Caption = 'X'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = sbtnGrillaClick
  end
  object mmMensajes: TMemo
    Left = 8
    Top = 352
    Width = 428
    Height = 82
    Lines.Strings = (
      '<Registro de actividades>')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object sbMensajes: TStatusBar
    Left = 0
    Top = 459
    Width = 1015
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Listo.'
    ExplicitTop = 449
    ExplicitWidth = 1005
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1015
    Height = 29
    Hint = 'Barra de controles'
    BorderWidth = 1
    ButtonHeight = 19
    ButtonWidth = 19
    Caption = 'Barra Herramientas'
    DrawingStyle = dsGradient
    EdgeBorders = [ebRight]
    EdgeInner = esLowered
    EdgeOuter = esRaised
    Flat = False
    List = True
    ParentShowHint = False
    ShowCaptions = True
    ShowHint = True
    TabOrder = 2
    Transparent = True
    ExplicitWidth = 1005
    object tbtnConectar: TToolButton
      Left = 0
      Top = 0
      Hint = 'Conectar a SQL.'
      Caption = 'C'
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      Style = tbsTextButton
      OnClick = tbtnConectarClick
    end
    object tbtnDesconectar: TToolButton
      Left = 19
      Top = 0
      Hint = 'Desconectar de SQL.'
      Caption = 'D'
      ImageIndex = 2
      Style = tbsTextButton
      OnClick = tbtnDesconectarClick
    end
    object tbtnGrilla: TToolButton
      Left = 38
      Top = 0
      Hint = 'Mostrar/Ocultar la grilla de celdas.'
      Caption = 'G'
      ImageIndex = 3
      Style = tbsTextButton
      OnClick = tbtnGrillaClick
    end
    object tbtnEditar: TToolButton
      Left = 57
      Top = 0
      Hint = 'Editar conexi'#243'n.'
      Caption = 'E'
      ImageIndex = 4
      Style = tbsTextButton
      OnClick = tbtnEditarClick
    end
    object tbtnSalir: TToolButton
      Left = 76
      Top = 0
      Hint = 'Salir de la aplicaci'#243'n.'
      Caption = 'S'
      ImageIndex = 1
      Style = tbsTextButton
      OnClick = tbtnSalirClick
    end
  end
  object DBAgenda: TDBGrid
    Left = 8
    Top = 66
    Width = 988
    Height = 136
    Hint = 'Planilla de Contactos'
    DataSource = ModuloDatos.DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'codigo'
        Title.Alignment = taCenter
        Title.Caption = 'C'#243'digo'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'nombre'
        Title.Alignment = taCenter
        Title.Caption = 'Nombres'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'apellido'
        Title.Alignment = taCenter
        Title.Caption = 'Apellidos'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'alias'
        Title.Alignment = taCenter
        Title.Caption = 'Alias'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'correo-e'
        Title.Alignment = taCenter
        Title.Caption = 'Correo Electr'#243'nico'
        Width = 180
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'telefono'
        Title.Alignment = taCenter
        Title.Caption = 'Tel'#233'fono'
        Width = 170
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Telegram-msj'
        Title.Alignment = taCenter
        Title.Caption = 'Mensajer'#237'a Telegram'
        Width = 170
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'X-msj'
        Title.Alignment = taCenter
        Title.Caption = 'Mensajer'#237'a X'
        Width = 170
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sitio1'
        Title.Alignment = taCenter
        Title.Caption = '1'#186' Sitio'
        Width = 280
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sitio2'
        Title.Alignment = taCenter
        Title.Caption = '2'#186' Sitio'
        Width = 280
        Visible = True
      end>
  end
  object DBNavegador: TDBNavigator
    Left = 40
    Top = 35
    Width = 240
    Height = 25
    DataSource = ModuloDatos.DataSource1
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel, nbRefresh, nbApplyUpdates, nbCancelUpdates]
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = DBNavegadorClick
  end
  object SpinButton1: TSpinButton
    Left = 8
    Top = 35
    Width = 20
    Height = 25
    Hint = 'Ajusta las dimensiones de la planilla Contactos.'
    DownGlyph.Data = {
      0E010000424D0E01000000000000360000002800000009000000060000000100
      200000000000D800000000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000008080000080800000808000000000000080800000808000008080000080
      8000008080000080800000808000000000000000000000000000008080000080
      8000008080000080800000808000000000000000000000000000000000000000
      0000008080000080800000808000000000000000000000000000000000000000
      0000000000000000000000808000008080000080800000808000008080000080
      800000808000008080000080800000808000}
    FocusControl = DBAgenda
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    UpGlyph.Data = {
      0E010000424D0E01000000000000360000002800000009000000060000000100
      200000000000D800000000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000000000000000000000000000000000000000000000000000000000000080
      8000008080000080800000000000000000000000000000000000000000000080
      8000008080000080800000808000008080000000000000000000000000000080
      8000008080000080800000808000008080000080800000808000000000000080
      8000008080000080800000808000008080000080800000808000008080000080
      800000808000008080000080800000808000}
    OnDownClick = SpinButton1DownClick
    OnUpClick = SpinButton1UpClick
  end
end
