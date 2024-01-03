object ModuloDatos: TModuloDatos
  OldCreateOrder = False
  Height = 219
  Width = 302
  object FDPhysPgDriverLink1: TFDPhysPgDriverLink
    Left = 192
    Top = 8
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'DriverID=PG'
      'Port=5432'
      'Server=localhost'
      'Database=agenda'
      'User_Name=postgres'
      'Password=poiu')
    LoginDialog = FDVCLLoginDialog1
    Left = 119
    Top = 48
  end
  object FDVCLLoginDialog1: TFDGUIxLoginDialog
    Provider = 'Forms'
    Caption = 'FireDAC Inicio de sesi'#243'n'
    Left = 40
    Top = 8
  end
  object FDQuery1: TFDQuery
    Filtered = True
    CachedUpdates = True
    FilterChanges = [rtModified, rtInserted, rtDeleted, rtUnmodified, rtHasErrors]
    DetailFields = 
      'alias;apellido;codigo;correo-e;nombre;sitio1;sitio2;telefono;Tel' +
      'egram-msj;X-msj'
    Connection = FDConnection1
    FormatOptions.AssignedValues = [fvStrsTrim2Len]
    FormatOptions.StrsTrim2Len = True
    SQL.Strings = (
      'SELECT * FROM contactos')
    Left = 72
    Top = 96
    object FDQuery1codigo: TIntegerField
      FieldName = 'codigo'
      Origin = 'codigo'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object FDQuery1nombre: TWideStringField
      FieldName = 'nombre'
      Origin = 'nombre'
      Size = 80
    end
    object FDQuery1apellido: TWideStringField
      FieldName = 'apellido'
      Origin = 'apellido'
      Size = 80
    end
    object FDQuery1correoe: TWideStringField
      FieldName = 'correo-e'
      Origin = '"correo-e"'
      Size = 80
    end
    object FDQuery1sitio1: TWideStringField
      FieldName = 'sitio1'
      Origin = 'sitio1'
      Size = 80
    end
    object FDQuery1sitio2: TWideStringField
      FieldName = 'sitio2'
      Origin = 'sitio2'
      Size = 80
    end
    object FDQuery1alias: TWideStringField
      FieldName = 'alias'
      Origin = 'alias'
      Size = 8190
    end
    object FDQuery1telefono: TWideStringField
      FieldName = 'telefono'
      Origin = 'telefono'
      Size = 8190
    end
    object FDQuery1Telegrammsj: TWideStringField
      FieldName = 'Telegram-msj'
      Origin = '"Telegram-msj"'
      Size = 8190
    end
    object FDQuery1Xmsj: TWideStringField
      FieldName = 'X-msj'
      Origin = '"X-msj"'
      Size = 8190
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = FDQuery1
    Left = 112
    Top = 152
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 24
    Top = 152
  end
  object OpenDialog1: TOpenDialog
    Left = 240
    Top = 136
  end
end
