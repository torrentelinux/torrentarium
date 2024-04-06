object frmControl: TfrmControl
  Left = 0
  Top = 0
  Width = 320
  Height = 240
  TabOrder = 0
  object SQLConsulta: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConexion
    Left = 160
    Top = 112
  end
  object SQLConexion: TSQLConnection
    ConnectionName = 'EjemploSQLite'
    DriverName = 'Sqlite'
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=Data.DbxSqlite'
      
        'DriverPackageLoader=TDBXSqliteDriverLoader,DBXSqliteDriver250.bp' +
        'l'
      
        'MetaDataPackageLoader=TDBXSqliteMetaDataCommandFactory,DbxSqlite' +
        'Driver250.bpl'
      'FailIfMissing=True'
      'Database=')
    AfterConnect = SQLConexionAfterConnect
    AfterDisconnect = SQLConexionAfterDisconnect
    Left = 96
    Top = 116
  end
  object dlgAbrirSQLite: TFileOpenDialog
    DefaultExtension = 'sdb'
    DefaultFolder = 'c:\'
    FavoriteLinks = <>
    FileName = 'ejemploSQLite.sdb'
    FileTypes = <
      item
        DisplayName = 'SQLite DataBase'
        FileMask = '*.sdb'
      end
      item
        DisplayName = 'SQLite DataBase'
        FileMask = '*.sqlite'
      end
      item
        DisplayName = 'SQLite DataBase'
        FileMask = '*.db'
      end
      item
        DisplayName = 'Todos'
        FileMask = '*.*'
      end>
    Options = []
    Title = 'Seleccione base de datos SQLite'
    Left = 240
    Top = 160
  end
end
