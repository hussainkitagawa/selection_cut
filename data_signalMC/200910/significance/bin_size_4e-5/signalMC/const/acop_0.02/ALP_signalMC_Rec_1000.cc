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

int ALP_signalMC_Rec_1000(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();



	// obtain rootfile
	TFile *file1 = new TFile("/Users/kitagawa/analysis_ALP/signalMC/diphoton.root"); //default is "read" option

	// obtain tree
	TTree* diphoton = (TTree*)file1->Get("diphoton");


	// Set output file
        //TFile* outputFile = new TFile("data_MC.root", "recreate");
        //TTree* outputTree = new TTree("data_MC", "data_MC");

/****************************************************************/
/*								*/							
/*								*/							
/*								*/							
/*			     signalMC				*/							
/*								*/							
/*								*/							
/*								*/							
/****************************************************************/


	//Set branch Address	
	//bool  MC_PhotonSelected1;
	//bool  MC_PhotonSelected2;
	//bool  MC_PhotonSelectEta1;
	//bool  MC_PhotonSelectAuthor1;
	//bool  MC_PhotonSelectCluster1;
	//bool  MC_PhotonSelectCleaning1;	
	//unsigned int  MC_PhotonSelectTightBitmap1;
	//bool  MC_PhotonSelectEta2;
	//bool  MC_PhotonSelectAuthor2;
	//bool  MC_PhotonSelectCluster2;	
	//bool  MC_PhotonSelectCleaning2;
	//bool  MC_PhotonSelectTight2;	
	//unsigned int  MC_PhotonSelectTightBitmap2;
	double  MC_PhotonPt1;		
	double  MC_PhotonEta1;	
	double  MC_PhotonPhi1;
	double  MC_PhotonE1;
	double  MC_PhotonPt2;			
	double  MC_PhotonEta2;		
	double  MC_PhotonPhi2;	
	double  MC_PhotonE2;		
	double  MC_DiphotonPt;			
	double  MC_DiphotonEta;		
	double  MC_DiphotonPhi;			
	double  MC_DiphotonE;			
	double  MC_DiphotonM;			
	double  MC_DiphotonAcop;		
	double  MC_DiphotonY;			
	double  MC_DiphotonXiA;			
	double  MC_DiphotonXiC;			
	double  MC_TruthPhotonPt1;		
	double  MC_TruthPhotonEta1;		
	double  MC_TruthPhotonPhi1;		
	double  MC_TruthPhotonE1;		
	double  MC_TruthPhotonPt2;		
	double  MC_TruthPhotonEta2;		
	double  MC_TruthPhotonPhi2;	
	double  MC_TruthPhotonE2;		
	double  MC_TruthDiphotonPt;		
	double  MC_TruthDiphotonEta;	
	double  MC_TruthDiphotonPhi;	
	double  MC_TruthDiphotonE;	
	double  MC_TruthDiphotonM;	
	double  MC_TruthDiphotonAcop;	
	double  MC_TruthDiphotonY;	
	double  MC_TruthDiphotonXiA;	
	double  MC_TruthDiphotonXiC;	
	double  MC_PhotonDeltaR1;	
	double  MC_PhotonDeltaR2;	
  	//diphoton->SetBranchAddress("PhotonSelected1",		&MC_PhotonSelected1);
  	//diphoton->SetBranchAddress("PhotonSelected2",		&MC_PhotonSelected2);
  	//diphoton->SetBranchAddress("PhotonSelectEta1",		&MC_PhotonSelectEta1);
  	//diphoton->SetBranchAddress("PhotonSelectAuthor1",	&MC_PhotonSelectAuthor1);
  	//diphoton->SetBranchAddress("PhotonSelectCluster1",	&MC_PhotonSelectCluster1);
  	//diphoton->SetBranchAddress("PhotonSelectCleaning1",	&MC_PhotonSelectCleaning1);
  	//diphoton->SetBranchAddress("PhotonSelectTight1",	&MC_PhotonSelectTight1);
  	//diphoton->SetBranchAddress("PhotonSelectTightBitmap1",	&MC_PhotonSelectTightBitmap1);
  	//diphoton->SetBranchAddress("PhotonSelectEta2",		&MC_PhotonSelectEta2);
  	//diphoton->SetBranchAddress("PhotonSelectAuthor2",	&MC_PhotonSelectAuthor2);
  	//diphoton->SetBranchAddress("PhotonSelectCluster2",	&MC_PhotonSelectCluster2);
  	//diphoton->SetBranchAddress("PhotonSelectCleaning2",	&MC_PhotonSelectCleaning2);
  	//diphoton->SetBranchAddress("PhotonSelectTight2",	&MC_PhotonSelectTight2);
  	//diphoton->SetBranchAddress("PhotonSelectTightBitmap2",	&MC_PhotonSelectTightBitmap2);
  	diphoton->SetBranchAddress("PhotonPt1",			&MC_PhotonPt1);
  	diphoton->SetBranchAddress("PhotonEta1",		&MC_PhotonEta1);
  	diphoton->SetBranchAddress("PhotonPhi1",		&MC_PhotonPhi1);
  	diphoton->SetBranchAddress("PhotonE1",			&MC_PhotonE1);
  	diphoton->SetBranchAddress("PhotonPt2",			&MC_PhotonPt2);
  	diphoton->SetBranchAddress("PhotonEta2",		&MC_PhotonEta2);
  	diphoton->SetBranchAddress("PhotonPhi2",		&MC_PhotonPhi2);
  	diphoton->SetBranchAddress("PhotonE2",			&MC_PhotonE2);
  	diphoton->SetBranchAddress("DiphotonPt",		&MC_DiphotonPt);
  	diphoton->SetBranchAddress("DiphotonEta",		&MC_DiphotonEta);
  	diphoton->SetBranchAddress("DiphotonPhi",		&MC_DiphotonPhi);
  	diphoton->SetBranchAddress("DiphotonE",			&MC_DiphotonE);
  	diphoton->SetBranchAddress("DiphotonM",			&MC_DiphotonM);
  	diphoton->SetBranchAddress("DiphotonAcop",		&MC_DiphotonAcop);
  	diphoton->SetBranchAddress("DiphotonY",			&MC_DiphotonY);
  	diphoton->SetBranchAddress("DiphotonXiA",		&MC_DiphotonXiA);
  	diphoton->SetBranchAddress("DiphotonXiC",		&MC_DiphotonXiC);
  	diphoton->SetBranchAddress("TruthPhotonPt1",		&MC_TruthPhotonPt1);
  	diphoton->SetBranchAddress("TruthPhotonEta1",		&MC_TruthPhotonEta1);
  	diphoton->SetBranchAddress("TruthPhotonPhi1",		&MC_TruthPhotonPhi1);
  	diphoton->SetBranchAddress("TruthPhotonE1",		&MC_TruthPhotonE1);
  	diphoton->SetBranchAddress("TruthPhotonPt2",		&MC_TruthPhotonPt2);
  	diphoton->SetBranchAddress("TruthPhotonEta2",		&MC_TruthPhotonEta2);
  	diphoton->SetBranchAddress("TruthPhotonPhi2",		&MC_TruthPhotonPhi2);
  	diphoton->SetBranchAddress("TruthPhotonE2",		&MC_TruthPhotonE2); 
  	diphoton->SetBranchAddress("TruthDiphotonPt",		&MC_TruthDiphotonPt);
  	diphoton->SetBranchAddress("TruthDiphotonEta",		&MC_TruthDiphotonEta);
  	diphoton->SetBranchAddress("TruthDiphotonPhi",		&MC_TruthDiphotonPhi);
  	diphoton->SetBranchAddress("TruthDiphotonE",		&MC_TruthDiphotonE);
  	diphoton->SetBranchAddress("TruthDiphotonM",		&MC_TruthDiphotonM);
  	diphoton->SetBranchAddress("TruthDiphotonAcop",		&MC_TruthDiphotonAcop);
  	diphoton->SetBranchAddress("TruthDiphotonY",		&MC_TruthDiphotonY);
  	diphoton->SetBranchAddress("TruthDiphotonXiA",		&MC_TruthDiphotonXiA);
  	diphoton->SetBranchAddress("TruthDiphotonXiC",		&MC_TruthDiphotonXiC);
  	diphoton->SetBranchAddress("PhotonDeltaR1",		&MC_PhotonDeltaR1);
  	diphoton->SetBranchAddress("PhotonDeltaR2",		&MC_PhotonDeltaR2);



	/*    histogram of Acoplanarity    */
      	TH1D *MC_Acop = new TH1D("", "", 540, 0, 0.0216); //binning size is 4e-5
	TH1D *MC_Acop_all = new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5
      	MC_Acop->SetTitle(";  DiphotonAcop; Events;");
      	//MC_Acop->GetXaxis()->CenterTitle();
      	//MC_Acop->GetYaxis()->SetTitleOffset(1.2);
      	//MC_Acop->GetYaxis()->CenterTitle();


	/**********   Start main Loop of MC (diphoton.root)   **********/
  	int MC_total = diphoton->GetEntries();  // total number of events
	double maximum_Acop = 0;
	double acoplanarity = 0.02;
  	for (int event = 0; event<MC_total; event++) {
		diphoton->GetEntry(event);	

		if (maximum_Acop <  MC_DiphotonAcop){
			
		maximum_Acop = MC_DiphotonAcop;		
		}
		
		MC_Acop_all->Fill(MC_DiphotonAcop);		

		//Arbitrary selction by user	
		if (!(MC_DiphotonAcop <= acoplanarity)) {
		continue;
		}

    		MC_Acop->Fill(MC_DiphotonAcop);
		
	}


	cout<< "####################  signalMC  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "maximum_Acop;                   " <<  maximum_Acop << endl;
        cout<< "MC_pass;               " <<    MC_Acop->GetEntries()<< endl;
        cout<< ""<<endl;
        cout<< "##########################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;






/****************************************************************/
/*                                                              */
/*      		Significance				*/
/*                                                              */
/*	events of signal is using rescaled events of signalMC	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/


	/****************************************/
	/*					*/
	/*	Rescale events of sinalMC	*/
	/*					*/
	/****************************************/

	MC_Acop->Sumw2();// Sumw2 has to be done before Scale()
	double luminosity = 32;
        double cross_section = 6.0821;
	double detecting_efficiency = (double)(7363)/10000;
	double expected_MC = luminosity * cross_section * detecting_efficiency; // expected detectable signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
	MC_Acop_all->Scale(expected_MC/7363);
	double bin_size = 0.0216/540;//binning size is 4e-5
	cout<< "bin_size" << bin_size<<endl;
	double Nbin  = acoplanarity/bin_size;
	double A4 = MC_Acop_all->Integral(0, Nbin);
	MC_Acop->Scale(A4/MC_Acop->GetEntries());


	cout<< "####################  data  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "Luminosity;                     " << luminosity << '\n';
        cout<< "Cross section;                  " << cross_section << '\n';
        cout<< "Detecting efficiency;           " << detecting_efficiency << '\n';
        cout<< "Expected MC events(1000GeV);    " << expected_MC << '\n';
        cout<< Form("Expected MC events between 0 and %f;        ", acoplanarity) << A4 << '\n';
        cout<< ""<<endl;
        cout<< "################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;



	/****************************************/
	/*					*/
	/*	Calculation of significance	*/
	/*					*/
	/****************************************/


	//Set parameters for Loop
        int Tgraph_i = 0;
        double MC_ibin = 0;

	 //histogram of TGraph :: Calculate significance for each ALP mass for 200GeV 
        //Set range of DiphotonAcop
        double end_DiphotonAcop = acoplanarity;
        const double Nplot = 10;
        double start_DiphotonAcop = end_DiphotonAcop/Nplot;
        const double increment = start_DiphotonAcop;
        double significance;
        double maximum_significance = 0;
        double diphotonacop;
        end_DiphotonAcop += increment;//according to the precision of double

        TGraph* significance_DiphotonAcop = new TGraph(Nplot);
        significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");
        significance_DiphotonAcop->GetXaxis()->SetLabelSize(0.04);
        significance_DiphotonAcop->GetYaxis()->SetLabelSize(0.04);
        significance_DiphotonAcop->SetMarkerStyle(20);
        significance_DiphotonAcop->SetMarkerSize(1.0);
        significance_DiphotonAcop->SetMarkerColor(1);
        significance_DiphotonAcop->SetMinimum(0);

        while(start_DiphotonAcop <= end_DiphotonAcop){
                //Set parameters for Loop
                significance = 0.;
                double MC_events = 0.;
                double data_events = 0.;

                ////  Pattern 2 ////
                MC_ibin = start_DiphotonAcop/bin_size;
                MC_events = MC_Acop->Integral(0, MC_ibin);
		data_events = 200 * MC_ibin;//background is constant according to Invariant Mass>=200GeV
	

                //calculation of significance
                significance = (double)(MC_events) /sqrt(MC_events + data_events);
                if(maximum_significance < significance){
                maximum_significance = significance;
                diphotonacop = start_DiphotonAcop;
                }

                //Fill to Tgraph
                significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);

		cout<<" significance;           "<< significance<<'\n';
                cout<<" MC_events;              "<< MC_events   << '\n';
                cout<<" data_events;            "<< data_events << '\n';
                cout<<" start_DiphotonAcop;     "<< setprecision(10) << start_DiphotonAcop <<'\n';
                cout<<" MC_ibin;                "<< MC_ibin <<'\n';
                cout<<""<<endl;
                cout<<""<<endl;


                start_DiphotonAcop += increment;
                ++Tgraph_i;

        }


        cout<<" maximum_significance;   "<< maximum_significance<<endl;
        cout<<" diphotonacop;           "<< diphotonacop<<endl;
	

/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				draw 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/

	//Significance
        TCanvas *c1000 = new TCanvas("c1000", "c1000");
        significance_DiphotonAcop->Draw("AP");
        c1000->Modified();
        c1000->SetWindowSize(830, 550);
        //significance_DiphotonAcop[i]->SetStats(0); //SetStats object is only for TH1D
        //significan_DiphotonAcop->SetTitle("PhotonPt2:PhotonPt1");
        //significan_DiphotonAcop->SetName("signalMC");

        //gPad->Update();
        //TPaveStats *st6 = (TPaveStats*)data_Pt_2D->FindObject("stats");
        //st6->SetName("mystats"); //it works whether it is command or not
        //st6->SetShadowColor(0);
        //gPad->Modified();
        //gPad->Update();
        c1000->Update();
        c1000->SaveAs("./pdf/1000.pdf");



//      outputFile->Close();


return 0;

}	
