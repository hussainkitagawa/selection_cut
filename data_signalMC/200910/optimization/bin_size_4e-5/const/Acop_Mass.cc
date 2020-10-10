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

	
        int Tgraph_i = 0;
	int ALP_mass;
	int n = 1;
	int Nplot = 14;

        TGraph* ALP = new TGraph(Nplot);
        ALP->SetTitle(" ; ALP Mass[GeV]; DiphotonAcop");
        ALP->GetXaxis()->SetLabelSize(0.03);
	ALP->GetXaxis()->SetRangeUser(100, 1900);
	 //gStyle->SetStripDecimals(false);
	((TGaxis*)ALP->GetYaxis())->SetMaxDigits(4);
        ALP->GetYaxis()->SetLabelSize(0.03);
	ALP->GetYaxis()->SetRangeUser(0, 0.00085);
        ALP->SetMarkerStyle(20);
        ALP->SetMarkerSize(1.0);
        ALP->SetMarkerColor(1);
        ALP->SetMinimum(0);

        for (int i = 0 ; i < 14; i++){
		

		if(i < 9){
		ALP_mass = 200+100*i;
		}
		else{
		ALP_mass = 1000+200*n;
		n++;
		}	
		
                double acoplanarity[14] = {0.00076, 0.0006, 0.00048, 0.00048, 0.0004, 0.00036, 0.00032, 0.00036, 0.00028, 0.00024, 0.00024, 0.0002, 0.0002, 0.0002};

                //Fill to Tgraph
                ALP->SetPoint(Tgraph_i, ALP_mass, acoplanarity[i]);


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
    	Acop_Mass_const->Modified();
	Acop_Mass_const->SetWindowSize(830, 550);
	Acop_Mass_const->Update();
     	Acop_Mass_const->SaveAs("./pdf/Acop_Mass_const.pdf");



return 0;

}	
