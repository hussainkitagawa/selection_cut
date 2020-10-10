//For C++
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <unistd.h>

using namespace std;

//For ROOT
#include <math.h>
#include "TH1D.h"
#include "TFile.h"
#include "TF1.h"
#include "TBranch.h"
#include "TList.h"
#include "TMath.h"
#include "TSystem.h"
#include "TTree.h"
#include "Rtypes.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TPaveStats.h"

//For ATLAS style
//#include "rootlogon.C"
#include "AtlasStyle.C"
//#include "AtlasLabels.C"

void Acop_Mass(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();

	TGraph* ALP_signal = new TGraph(1);
	ALP_signal->SetTitle(" ; ALP mass [GeV]; Diphoton acoplanarity [#times 10^{-3}]");
        ALP_signal->GetXaxis()->SetLabelSize(0.05);
        ALP_signal->GetYaxis()->SetLabelSize(0.05);
        ALP_signal->GetXaxis()->SetRangeUser(100, 2100);
        ALP_signal->GetYaxis()->SetRangeUser(0, 0.00085);
        ALP_signal->SetPoint(0, 1000, 0.00058);
	//gStyle->SetStripDecimals();
	((TGaxis*)ALP_signal->GetYaxis())->SetMaxDigits(2);
        ALP_signal->SetMarkerStyle(22);
        ALP_signal->SetMarkerSize(1);
        ALP_signal->SetMarkerColor(2);
        ALP_signal->SetMinimum(0);
 

        int Tgraph_i = 0;
	int ALP_mass;
	int n = 1;
	const int Nplot = 14;
	
	
	
        TGraph* ALP = new TGraph(Nplot);
        ALP->SetTitle(" ; ALP mass [GeV]; Diphoton acoplanarity [#times 10^{-3}]");
        ALP->GetXaxis()->SetLabelSize(0.05);
        ALP->GetYaxis()->SetLabelSize(0.05);
	ALP->GetXaxis()->SetRangeUser(100, 2100);
	ALP->GetYaxis()->SetRangeUser(0, 0.00085);
	//gStyle->SetStripDecimals();
	((TGaxis*)ALP->GetYaxis())->SetMaxDigits(2);
        ALP->SetMarkerStyle(20);
        ALP->SetMarkerSize(1.0);
        ALP->SetMarkerColor(1);
        ALP->SetMinimum(0);
        for (int i = 0 ; i < Nplot; i++){
		

		if(i < 9){
		ALP_mass = 200+100*i;
		}
		else{
		ALP_mass = 1000+200*n;
		n++;
		}	
		
                double acoplanarity[Nplot] = {0.00074, 0.0006, 0.00046, 0.00048, 0.00042, 0.00038, 0.00034, 0.00034, 0.00028,0.00026, 0.00022, 0.00022, 0.0002, 0.0002};

                //Fill to Tgraph
		cout<< "Tgraph = " << Tgraph_i <<endl;
		cout<< "acoplanarity = " << acoplanarity[i] << endl;
		cout<< "i = " << i << endl;
                ALP->SetPoint(Tgraph_i, ALP_mass, acoplanarity[i]);
			
		//include errors
		//graph = new TGraphErrors(index, x, y, x_error, y_error);
                ++Tgraph_i;

        }


/*****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				Draw 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/
	gStyle->SetPadGridX(1);	
	gStyle->SetPadGridY(1);	
	TCanvas *Acop_Mass_const = new TCanvas("Acop_Mass_const", "Acop_Mass_const");
	ALP->Draw("AP");
	ALP_signal->Draw("P");
    	Acop_Mass_const->Modified();
	Acop_Mass_const->SetWindowSize(830, 550);
	
	TLegend *legend = new TLegend();
        //legend->SetNColumns(3);
        legend->AddEntry(ALP_signal, "Signal MC", "p");
        legend->AddEntry(ALP, "Generator level", "p");
        legend->SetFillColor(0);
        legend->SetBorderSize(1);
        legend->SetShadowColor(1);
        //gStyle->SetStripDecimals(false);
        //((TGaxis*)significance_DiphotonAcop->GetYaxis())->SetMaxDigits(2);
        legend->Draw();
        gPad->RedrawAxis();
        gPad->Update();
	Acop_Mass_const->Update();
     	//Acop_Mass_const->SaveAs("./pdf/Acop_Mass_const.pdf");




}

/*void DrawCol()
{
   Int_t i,n;
   Double_t x,y;
   TLatex *l;

   TGraph *g = (TGraph*)gPad->GetListOfPrimitives()->FindObject("Graph");
   n = g->GetN();
   cout<< "n = "<< n <<endl;
   TMarker *m;
   for (i=0; i<n; i++) {
       g->GetPoint(i,x,y);
	if(i!=9){
       m = new TMarker(x,y,20);//3rd option is MarkerStyle
       m->SetMarkerColor(1);
       m->SetMarkerStyle(20);
       m->SetMarkerSize(1.0);
	}
	else{
	  m = new TMarker(x,y,22);
       	  m->SetMarkerColor(1);
       	  m->SetMarkerStyle(22);
       	  m->SetMarkerSize(1.3);
	}
       m->Paint();
   }
}
*/	
