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
	TBevel *Bevel1;
	TMaskEdit *meDirIP;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TMaskEdit *mePuerto;
	TStatusBar *StatusBar1;
	TButton *btnBorrar;
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
