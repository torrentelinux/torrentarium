// cliente_tcp.h
// Edmund Muslok -- Mayo de 2022
// Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
//---------------------------------------------------------------------------

#ifndef cliente_tcpH
#define cliente_tcpH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TfrmClienteTCP : public TForm
{
__published:	// IDE-managed Components
	TButton *btnConectar;
	TButton *btnEnviar;
	TButton *btnBorrar;
	TButton *btnSalir;
	TButton *btnConfig;
	TMemo *mmSalida;
	TEdit *edtComando;
	TClientSocket *SocketCliente;

	void __fastcall btnConectarClick(TObject *Sender);
	void __fastcall btnEnviarClick(TObject *Sender);
	void __fastcall btnBorrarClick(TObject *Sender);
	void __fastcall btnSalirClick(TObject *Sender);
	void __fastcall btnConfigClick(TObject *Sender);
	void __fastcall SocketClienteConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SocketClienteConnecting(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SocketClienteDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SocketClienteRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SocketClienteError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SocketClienteLookup(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SocketClienteWrite(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall edtComandoKeyPress(TObject *Sender, System::WideChar &Key);


private:	// User declarations
public:		// User declarations
	__fastcall TfrmClienteTCP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmClienteTCP *frmClienteTCP;
//---------------------------------------------------------------------------
#endif