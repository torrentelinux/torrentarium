// cliente_tcp.cpp
// Edmund Muslok -- Mayo de 2022
// Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
#pragma hdrstop

#include "cliente_tcp.h"
#include "cliente_config.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmClienteTCP *frmClienteTCP;

//---------------------------------------------------------------------------
__fastcall TfrmClienteTCP::TfrmClienteTCP(TComponent* Owner) : TForm(Owner)
{
   // Valores establecidos por omisión
   SocketCliente->Address = "127.0.0.1";
   SocketCliente->Port = 337;

   // El botón enviar y la línea de comandos están deshabilitados
   edtComando->Enabled = false;
   btnEnviar->Enabled = false;

}
//---------------------------------------------------------------------------
// Evento Ajustes de la conexión
void __fastcall TfrmClienteTCP::btnConfigClick(TObject *Sender)
{
	bool error = false;
	int respuesta = -1;
	String salida;

   respuesta = DlgAjustes->ShowModal();
   if(respuesta == 1)
   {
     if(DlgAjustes->PuertoTCP.IsEmpty() == true)
     {
	// El nº de puerto es incorrecto
	salida = "[I] Nº de puerto. Modifique nuevamente.\r\n";
        error = true;
     }

     if(DlgAjustes->DirIP.Length() < 4)
     {
	// La dir. IP es incorrecta
	salida = salida + "[I] Dirección IPv4. Modifique nuevamente.";
        error = true;
     }

     if(error == false)
     {
	// Sí hubo cambios en la dir. IP y en el nº de puerto
	salida = "[S] IPv4:TCP = " + DlgAjustes->DirIP + ":" + DlgAjustes->PuertoTCP;

	SocketCliente->Address = DlgAjustes->DirIP;
	SocketCliente->Port = DlgAjustes->PuertoTCP.ToInt();
     }
   }
   else
     // No hubo cambios en la dir. IP y en el nº de puerto
     salida = "[N] IPv4:TCP = " + SocketCliente->Address + ":" + SocketCliente->Port;

   mmSalida->Text = mmSalida->Text + salida;
   mmSalida->Lines->Append("-------\r\n");
}
//---------------------------------------------------------------------------
// Evento Conectar/Desconectar conexión
void __fastcall TfrmClienteTCP::btnConectarClick(TObject *Sender)
{
   // Activa la conexión cliente hacia el servidor
   SocketCliente->Active = true;

   edtComando->Enabled = true;
   btnEnviar->Enabled = true;

   if(SocketCliente->Socket->Connected == true)
   {
	// Se procede a desactivar la conexión
	mmSalida->Text = mmSalida->Text + "[D] Conexión.\r\n";

	btnConectar->Caption = "Conectar";
	btnEnviar->Enabled = false;
	edtComando->Enabled = false;

	// Desactiva la conexión cliente hacia el servidor
	SocketCliente->Active = false;
   }
   else
	// Se notifica que la conexión está activa
	mmSalida->Text = mmSalida->Text + "[A] Conexión.\r\n";
}
//---------------------------------------------------------------------------
// Evento Salir
void __fastcall TfrmClienteTCP::btnSalirClick(TObject *Sender)
{
   // Cierra la conexión
   SocketCliente->Close();

   // Cierra la ventana principal
   frmClienteTCP->Close();
}
//---------------------------------------------------------------------------
// Evento Enviar
void __fastcall TfrmClienteTCP::btnEnviarClick(TObject *Sender)
{
	String texto;

   // Añade el fin de línea '\n' al final del comando a enviar
   texto = edtComando->Text + "\n";

   // Muestra en pantalla lo que va a enviar al servidor
   mmSalida->Text = mmSalida->Text + "enviando: [" + texto + "]\r\n";

   // Deja en blanco la línea de comandos
   edtComando->Clear();

   // Envía al servidor el mensaje
   SocketCliente->Socket->SendText(texto);
   mmSalida->Lines->Append("------\r\n");
}
//---------------------------------------------------------------------------
// Evento Borrar
void __fastcall TfrmClienteTCP::btnBorrarClick(TObject *Sender)
{
   // Borra todo el registro de actividades efectuadas con el servidor
   mmSalida->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmClienteTCP::SocketClienteConnecting(TObject *Sender, TCustomWinSocket *Socket)
{
   mmSalida->Text = mmSalida->Text + "Conectando al servidor "+ SocketCliente->Address +" ...\r\n";
   btnConectar->Caption = "[Desconectar]";
}
//---------------------------------------------------------------------------
void __fastcall TfrmClienteTCP::SocketClienteDisconnect(TObject *Sender, TCustomWinSocket *Socket)
{
   SocketCliente->Close();

   mmSalida->Text = mmSalida->Text + "Desconectado.\r\n";
   mmSalida->Lines->Append("------\r\n");

   btnEnviar->Enabled = false;
   edtComando->Enabled = false;
   btnConectar->Caption = "Conectar";
}
//---------------------------------------------------------------------------
void __fastcall TfrmClienteTCP::SocketClienteConnect(TObject *Sender, TCustomWinSocket *Socket)
{
   btnConectar->Caption = "<Desconectar>";
   mmSalida->Text = mmSalida->Text + "Conexión establecida.";
   mmSalida->Lines->Append("------\r\n");
}
//---------------------------------------------------------------------------
void __fastcall TfrmClienteTCP::SocketClienteRead(TObject *Sender, TCustomWinSocket *Socket)
{
	String datos;

   // Lee los mensajes recibidos que vienen del servidor
   datos = Socket->ReceiveText();

   mmSalida->Text = mmSalida->Text + "Servidor: [" + datos + "]";
   mmSalida->Lines->Append("------\r\n");
}
//---------------------------------------------------------------------------
void __fastcall TfrmClienteTCP::SocketClienteError(TObject *Sender, TCustomWinSocket *Socket,
	TErrorEvent ErrorEvent, int &ErrorCode)
{
   // El servidor se encuentra inactivo
   mmSalida->Text = mmSalida->Text + "\r\nNo hay conexión al servidor: " + ErrorCode + "\r\n";

   switch(ErrorEvent)
   {
     case eeGeneral: mmSalida->Lines->Append("Error de comunicación.");
		     break;
     case eeSend: mmSalida->Lines->Append("Error de envío.");
		     break;
     case eeReceive: mmSalida->Lines->Append("Error de recepción.");
		     break;
     case eeConnect: mmSalida->Lines->Append("Error de conexión.");
		     break;
     case eeDisconnect: mmSalida->Lines->Append("Error de desconexión.");
		     break;
     case eeAccept: mmSalida->Lines->Append("Error al establecer conexión.");
		     break;
     case eeLookup: mmSalida->Lines->Append("Error de inicializar la conexión.");
		     break;
   }

   mmSalida->Text = mmSalida->Text + "Intente más tarde.";
   mmSalida->Lines->Append("------\r\n");

   SocketCliente->Active = false;
   ErrorCode = 0;

   btnConectar->Caption = "Conectar";
   edtComando->Enabled = false;
   btnEnviar->Enabled = false;
}
//---------------------------------------------------------------------------
