// cliente_config.h
// Edmund Muslok -- Junio de 2022
// Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
// Configura la dirección IPv4 y el nº de puerto asignado por el usuario.
//----------------------------------------------------------------------------
#ifndef cliente_configH
#define cliente_configH
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TDlgAjustes : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *btnBorrar;
	TBevel *Bevel1;
	TMaskEdit *meDirIP;
	TMaskEdit *mePuerto;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStatusBar *StatusBar1;
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall btnBorrarClick(TObject *Sender);
private:
public:
	String DirIP;
        String PuertoTCP;
	virtual __fastcall TDlgAjustes(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDlgAjustes *DlgAjustes;
//----------------------------------------------------------------------------
#endif    
