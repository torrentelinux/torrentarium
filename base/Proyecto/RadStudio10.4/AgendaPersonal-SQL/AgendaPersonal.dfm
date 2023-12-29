object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'Agenda Personal'
  ClientHeight = 322
  ClientWidth = 444
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
    Width = 444
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Listo.'
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 444
    Height = 29
    Hint = 'Barra de controles'
    ButtonHeight = 19
    ButtonWidth = 19
    Caption = 'ToolBar1'
    List = True
    ParentShowHint = False
    ShowCaptions = True
    AllowTextButtons = True
    ShowHint = True
    TabOrder = 2
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
      Left = 23
      Top = 0
      Hint = 'Desconectar de SQL.'
      Caption = 'D'
      ImageIndex = 2
      Style = tbsTextButton
      OnClick = tbtnDesconectarClick
    end
    object tbtnSalir: TToolButton
      Left = 46
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
    Width = 428
    Height = 120
    DataSource = ModuloDatos.DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
end
