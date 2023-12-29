object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'Agenda Personal'
  ClientHeight = 322
  ClientWidth = 1005
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object mmMensajes: TMemo
    Left = 8
    Top = 208
    Width = 428
    Height = 82
    Lines.Strings = (
      '<Registro de actividades>')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object sbMensajes: TStatusBar
    Left = 0
    Top = 303
    Width = 1005
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Listo.'
    ExplicitWidth = 444
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1005
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
    ExplicitWidth = 444
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
    object tbtnSalir: TToolButton
      Left = 38
      Top = 0
      Hint = 'Salir de la aplicaci'#243'n.'
      Caption = 'S'
      ImageIndex = 1
      Style = tbsTextButton
      OnClick = tbtnSalirClick
    end
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 35
    Width = 988
    Height = 140
    Hint = 'Contactos'
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
        Width = 44
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'nombre'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Nombres'
        Width = 132
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'apellido'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Apellidos'
        Width = 132
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'correo-e'
        Title.Alignment = taCenter
        Title.Caption = 'Correo electr'#243'nico'
        Width = 132
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sitio1'
        Title.Alignment = taCenter
        Title.Caption = '1'#186' Sitio'
        Width = 273
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sitio2'
        Title.Alignment = taCenter
        Title.Caption = '2'#186' Sitio'
        Visible = True
      end>
  end
end
