object ModuloDatos: TModuloDatos
  OldCreateOrder = False
  Height = 240
  Width = 377
  object FDPhysPgDriverLink1: TFDPhysPgDriverLink
    Left = 64
    Top = 80
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=postgres'
      'Server=localhost'
      'Port=5432'
      'Password=xxxx'
      'Database=agenda'
      'DriverID=PG')
    LoginDialog = FDVCLLoginDialog1
    Left = 143
    Top = 16
  end
  object FDVCLLoginDialog1: TFDGUIxLoginDialog
    Provider = 'Forms'
    Caption = 'FireDAC Inicio de sesi'#243'n'
    Left = 144
    Top = 128
  end
  object FDQuery1: TFDQuery
    Filtered = True
    CachedUpdates = True
    FilterChanges = [rtModified, rtInserted, rtDeleted, rtUnmodified, rtHasErrors]
    Connection = FDConnection1
    FormatOptions.AssignedValues = [fvStrsTrim2Len]
    FormatOptions.StrsTrim2Len = True
    SQL.Strings = (
      'SELECT * FROM contactos')
    Left = 184
    Top = 80
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
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = FDQuery1
    Left = 304
    Top = 56
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 280
    Top = 136
  end
end
