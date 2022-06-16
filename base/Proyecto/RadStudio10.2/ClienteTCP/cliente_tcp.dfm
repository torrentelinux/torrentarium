object frmClienteTCP: TfrmClienteTCP
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Cliente TCP'
  ClientHeight = 261
  ClientWidth = 360
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnConectar: TButton
    Left = 142
    Top = 18
    Width = 80
    Height = 25
    Hint = 'Establece la conexi'#243'n con el servidor IP.'
    Caption = 'Conectar'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = btnConectarClick
  end
  object mmSalida: TMemo
    Left = 8
    Top = 49
    Width = 344
    Height = 146
    Hint = 'Area Registro de Actividades.'
    Color = clInfoBk
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'en espera...')
    ParentFont = False
    ParentShowHint = False
    ScrollBars = ssBoth
    ShowHint = True
    TabOrder = 5
  end
  object edtComando: TEdit
    Left = 8
    Top = 209
    Width = 140
    Height = 21
    Hint = 'L'#237'nea de comandos.'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    TextHint = '<escriba aqu'#237' el comando>'
  end
  object btnEnviar: TButton
    Left = 163
    Top = 209
    Width = 75
    Height = 25
    Hint = 'Env'#237'a al servidor el comando escrito por el usuario.'
    Caption = 'Enviar'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnClick = btnEnviarClick
  end
  object btnBorrar: TButton
    Left = 277
    Top = 207
    Width = 75
    Height = 25
    Hint = 'Borra la l'#237'nea de comandos y el registro de actividades.'
    Caption = 'Borrar'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = btnBorrarClick
  end
  object btnSalir: TButton
    Left = 277
    Top = 18
    Width = 75
    Height = 25
    Hint = 'Termina la ejecuci'#243'n de la aplicaci'#243'n.'
    Caption = 'Salir'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = btnSalirClick
  end
  object btnConfig: TButton
    Left = 8
    Top = 18
    Width = 75
    Height = 25
    Hint = 'Ajustes en dir. IP y n'#186' puerto.'
    Caption = 'Ajustes'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnClick = btnConfigClick
  end
  object SocketCliente: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Host = 'localhost'
    Port = 337
    OnConnecting = SocketClienteConnecting
    OnConnect = SocketClienteConnect
    OnDisconnect = SocketClienteDisconnect
    OnRead = SocketClienteRead
    OnError = SocketClienteError
    Left = 240
    Top = 216
  end
end
