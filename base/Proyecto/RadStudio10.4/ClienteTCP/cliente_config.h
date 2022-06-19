// Encabezamiento: cliente_config.h
// Autor: Edmund Muslok -- Mayo de 2022.
// Propósito: Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
//            Define la ventana Ajustes.
//            Puede modificar la dir. IP y el nº de puerto.
// Observac.: Para Embarcadero RadStudio 2010, 10.2, 10.4 y versiones superiores.
//----------------------------------------------------------------------------

#ifndef cliente_configH
#define cliente_configH
//----------------------------------------------------------------------------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
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
