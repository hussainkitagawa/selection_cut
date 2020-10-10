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

int main(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();



	// obtain rootfile
	TFile *file1 = new TFile("/Users/kitagawa/analysis_ALP/signalMC/diphoton.root"); //default is "read" option
	TFile *file2 = new TFile("/Users/kitagawa/analysis_ALP/data/data.root"); 

	// obtain tree
	TTree* diphoton = (TTree*)file1->Get("diphoton");
	TTree* data = (TTree*)file2->Get("TreePhoton");


	// Set output file
        TFile* outputFile = new TFile("data_MC.root", "recreate");
        TTree* outputTree = new TTree("data_MC", "data_MC");

/****************************************************************/
/*Read signalMC.root and add its TTree to a new file,		*/							
/*data_MC.root.							*/							
/*								*/							
/*			     signalMC				*/							
/*								*/							
/*								*/							
/*								*/							
/****************************************************************/


	//Set branch Address	
/*	bool  MC_PhotonSelected1;
	bool  MC_PhotonSelected2;
	bool  MC_PhotonSelectEta1;
	bool  MC_PhotonSelectAuthor1;
	bool  MC_PhotonSelectCluster1;
	bool  MC_PhotonSelectCleaning1;	
	unsigned int  MC_PhotonSelectTightBitmap1;
	bool  MC_PhotonSelectEta2;
	bool  MC_PhotonSelectAuthor2;
	bool  MC_PhotonSelectCluster2;	
	bool  MC_PhotonSelectCleaning2;
	bool  MC_PhotonSelectTight2;	
	unsigned int  MC_PhotonSelectTightBitmap2;
*/	double  MC_PhotonPt1;		
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
/*  	diphoton->SetBranchAddress("PhotonSelected1",		&MC_PhotonSelected1);
  	diphoton->SetBranchAddress("PhotonSelected2",		&MC_PhotonSelected2);
  	diphoton->SetBranchAddress("PhotonSelectEta1",		&MC_PhotonSelectEta1);
  	diphoton->SetBranchAddress("PhotonSelectAuthor1",	&MC_PhotonSelectAuthor1);
  	diphoton->SetBranchAddress("PhotonSelectCluster1",	&MC_PhotonSelectCluster1);
  	diphoton->SetBranchAddress("PhotonSelectCleaning1",	&MC_PhotonSelectCleaning1);
  	diphoton->SetBranchAddress("PhotonSelectTight1",	&MC_PhotonSelectTight1);
  	diphoton->SetBranchAddress("PhotonSelectTightBitmap1",	&MC_PhotonSelectTightBitmap1);
  	diphoton->SetBranchAddress("PhotonSelectEta2",		&MC_PhotonSelectEta2);
  	diphoton->SetBranchAddress("PhotonSelectAuthor2",	&MC_PhotonSelectAuthor2);
  	diphoton->SetBranchAddress("PhotonSelectCluster2",	&MC_PhotonSelectCluster2);
  	diphoton->SetBranchAddress("PhotonSelectCleaning2",	&MC_PhotonSelectCleaning2);
  	diphoton->SetBranchAddress("PhotonSelectTight2",	&MC_PhotonSelectTight2);
  	diphoton->SetBranchAddress("PhotonSelectTightBitmap2",	&MC_PhotonSelectTightBitmap2);
*/  	diphoton->SetBranchAddress("PhotonPt1",			&MC_PhotonPt1);
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
      	TH1D *MC_Acop = new TH1D("", "", 540, 0, 0.0216);
      	MC_Acop->SetTitle("Number of events;  DiphotonAcop;");
      	//hist1->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();

      	TH1D *MC_Pt = new TH1D("", "", 175, 0, 350);
      	MC_Pt->SetTitle("Number of events;  DiphotonPt;");
      	//hist2->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);
      	//hist2->GetYaxis()->CenterTitle();

      	TH2D *MC_Pt_2D = new TH2D("", "", 100, 0, 1000, 100, 0, 1000);//1000->700
      	//hist2->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);




	/**********   Start main Loop of MC (diphoton.root)   **********/
  	int MC_total = diphoton->GetEntries();  // total number of events
 	std::cout<< " Total events of MC   = "<< MC_total <<'\n';
	double max_Acop;
	double MC_pass = 0;
  	for (int event = 0; event<MC_total; event++) {
	diphoton->GetEntry(event);	

	if (max_Acop <  MC_DiphotonAcop){
		
	max_Acop = MC_DiphotonAcop;		
	}
	// Fill values to output branch	
	if (!(MC_DiphotonAcop <= 0.02)) {

	continue;
	}

    	MC_Acop->Fill(MC_DiphotonAcop);
      	MC_Pt->Fill(MC_DiphotonPt);
	MC_Pt_2D->Fill(MC_PhotonPt1, MC_PhotonPt2);
	
	MC_pass++;
	}

	std::cout<< " max_MC_Acop = "<< max_Acop;
	std::cout<< " MC_selected  = " << MC_pass << '\n';
/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				data 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/


	//Set branch address
  	UInt_t data_RunNumber = 0;
	ULong64_t data_EventNumber = 0;
	UInt_t data_LumiBlock = 0;
  	double data_PhotonAcop = 0;
	double data_PhotonPt1= 0;
	double data_PhotonPt2= 0;
	double data_PhotonPhi1= 0;
	double data_PhotonPhi2= 0;
	double data_PhotonEta1= 0;
	double data_PhotonEta2= 0;
	double data_PhotonE1= 0;
	double data_PhotonE2= 0;
	double data_PhotonY= 0;
	double data_PhotonPt= 0;
	double data_PhotonXiA= 0;
	double data_PhotonXiC= 0;
	double data_PhotonInvMass = 0;
	double data_PhotonTrkPt = 0;
  	data->SetBranchAddress("RunNumber",	&data_RunNumber);
  	data->SetBranchAddress("EventNumber",	&data_EventNumber);
  	data->SetBranchAddress("LumiBlock",	&data_LumiBlock);
  	data->SetBranchAddress("PhotonAcop",	&data_PhotonAcop);
  	data->SetBranchAddress("PhotonPt1",	&data_PhotonPt1);
  	data->SetBranchAddress("PhotonPt2",	&data_PhotonPt2);
  	data->SetBranchAddress("PhotonPhi1",	&data_PhotonPhi1);
  	data->SetBranchAddress("PhotonPhi2",	&data_PhotonPhi2);
  	data->SetBranchAddress("PhotonEta1",	&data_PhotonEta1);
  	data->SetBranchAddress("PhotonEta2",	&data_PhotonEta2);
  	data->SetBranchAddress("PhotonE1",	&data_PhotonE1);
  	data->SetBranchAddress("PhotonE2",	&data_PhotonE2);
  	data->SetBranchAddress("PhotonY",	&data_PhotonY);
  	data->SetBranchAddress("PhotonPt",	&data_PhotonPt);
  	data->SetBranchAddress("PhotonXiA",	&data_PhotonXiA);
  	data->SetBranchAddress("PhotonXiC",	&data_PhotonXiC);
  	data->SetBranchAddress("PhotonInvMass",	&data_PhotonInvMass);
  	data->SetBranchAddress("PhotonTrkPt",	&data_PhotonTrkPt);


	/*    histogram of Acoplanarity    */
//     	TH1D *data_Acop = new TH1D("", "", 1, 0, 0.021); //for constant
      	TH1D *data_Acop = new TH1D("", "", 540, 0, 0.0216);
      	data_Acop->SetTitle("Number of events;  DiphotonAcop;");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();

      	TH1D *data_Pt = new TH1D("", "", 175, 0, 350);
      	data_Pt->SetTitle("Number of events;	DiphotonPt; ");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);
      	//hist2->GetYaxis()->CenterTitle();

      	TH2D *data_Pt_2D = new TH2D("", "", 100, 0, 1000, 100, 0, 1000);//Actual limiti for Pt1 is 2200
      	data_Pt_2D->SetTitle(" ; PhotonPt1; PhotonPt2");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);



	/**********	Start main loop of data	(data.root)	**********/
  	Long64_t data_total = data->GetEntries();  // total number of events
	long int data_selected_event = 0;
 	std::cout<< " Total events of data  = "<< data_total <<'\n';

  	for (Long64_t ievent = 0; ievent <  data_total; ievent++) {
      	data->GetEntry(ievent);
      	//std::cout<<" ****** Event = " << ievent <<" ******\n";
	
	//set cut criteria 
        if (!(data_PhotonPt1 >= 10  && data_PhotonPt2 >= 10)) {

        continue;
        }
        if (!(data_PhotonAcop <= 0.02)) {

        continue;
        }
        if (!(fabs(data_PhotonEta1 < 2.5) && fabs(data_PhotonEta2 < 2.5))) {

        continue;
        }
        if (!(data_PhotonInvMass >= 200)) {

        continue;
        }

	
	data_selected_event++;

      	data_Acop->Fill(data_PhotonAcop);
      	data_Pt->Fill(data_PhotonPt);
	data_Pt_2D->Fill(data_PhotonPt1, data_PhotonPt2);

	
//	if (data_selected_event == 10000) {
//	break;
//	}


	} //Loop end
	
	
	
	std::cout<< "Selected events of data  = " << data_selected_event << '\n';


	/********************************/
	/*				*/
	/*	fill constant value 	*/
	/*				*/
	/********************************/
	/*
	double ktotal = 0.021;
	for (double kevent = 0; kevent < ktotal; kevent++) {
	
		for (int k_event = 0; k_event <= 3000; k_event++){
		data_Acop->Fill(0.01);
		}
	}
	*/

/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*		significance: background is constant		*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/
/*

	//Set range of DiphotonAcop
	double end_DiphotonAcop = 0.022;
	double start_DiphotonAcop = 0.002;
	//Set parameters for Loop
	long double significance;
	const double sig_n = end_DiphotonAcop/start_DiphotonAcop;
	int Tgraph_i= 0;
	double bin_size = 0.021/500;

	//histogram of TGraph
	TGraph *significance_DiphotonAcop = new TGraph(sig_n); 
      	significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");
      	significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");

	while (start_DiphotonAcop <= end_DiphotonAcop) {
		//Set parameters for Loop
		significance = 0;
 		double MC_events = 0;
 		double data_events = 0;
	

		//Loop for signalMC			
		Long64_t total_MC = diphoton->GetEntries(); 
		cout<< " total MC" << total_MC<< '\n';
		for (Long64_t ievent_MC = 0; ievent_MC < total_MC; ievent_MC++) {
		diphoton->GetEntry(ievent_MC);
        	if (MC_DiphotonAcop <= start_DiphotonAcop) {
		++MC_events;
		}
		else;
		}	

		data_events = 3000 * (start_DiphotonAcop / bin_size);

		//Fill to histogram TH1D version
		significance = (double)(MC_events) /sqrt(data_events);
		
		//Fill to Tgraph
		significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);

		cout<< " significance = "<< significance <<'\n';
		cout<<" MC_events = " 	<< MC_events	<< " start_DiphotonAcop " << start_DiphotonAcop <<'\n';
		cout<<" data_events = " << data_events	<< " start_DiphotonAcop " << start_DiphotonAcop <<'\n';


		start_DiphotonAcop += 0.002;
		++Tgraph_i;

	}


*/





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

	/*    histogram of Acoplanarity    */
      	TH1D *MC_Acop_all = new TH1D("", "", 540, 0, 0.0216);
	/**********   Start main Loop of MC (diphoton.root)   **********/
  	for (int event = 0; event<MC_total; event++) {
	diphoton->GetEntry(event);	

	// Fill values to output branch	
	if (!(MC_DiphotonAcop <= 0.02)) {

	continue;
	}

    	MC_Acop_all->Fill(MC_DiphotonAcop);
	}

	MC_Acop->Sumw2();// Sumw2 has to be done before Scale()
	long double A2 = 32 * 7363 * 6.0821 / 10000; // expected detected signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
	long double A3 = diphoton->GetEntries();// 7363 events
	cout << " A2 = " << A2 <<'\n';
	cout << " A3 = " << A3 <<'\n';
	MC_Acop_all->Scale(A2/A3);
	double A4 = MC_Acop_all->Integral(0, 540);
	cout << " A4 = " << A4 <<'\n';
	MC_Acop->Scale(A4/MC_pass);
	//cout << " A5 = " << MC_Acop->Integral(0, 50) <<'\n';


	/****************************************/
	/*					*/
	/*	Calculation of significance	*/
	/*					*/
	/****************************************/
	//Set range of DiphotonAcop
	double end_DiphotonAcop = 0.022;
	double start_DiphotonAcop = 0.002;

	//Set parameters for Loop
	long double significance;
	const double sig_n = end_DiphotonAcop/start_DiphotonAcop;
	int Tgraph_i= 0;
	int MC_nbins;

	//histogram of TGraph
	TGraph *significance_DiphotonAcop = new TGraph(sig_n); 
      	significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");

	while (start_DiphotonAcop <= end_DiphotonAcop) {
		//Set parameters for Loop
		significance = 0;
 		double MC_events = 0;
 		double data_events = 0;
	

		//Loop for signalMC			
		//Long64_t total_MC = diphoton->GetEntries(); 
		//cout<< " total MC" << total_MC<< '\n';
		//for (Long64_t ievent_MC = 0; ievent_MC < total_MC; ievent_MC++) {
		//diphoton->GetEntry(ievent_MC);
        	//if (MC_DiphotonAcop <= start_DiphotonAcop) {
		//++MC_events;
		//}
		//else;
		//}	
		MC_events = MC_Acop->Integral(0, MC_nbins = start_DiphotonAcop /(0.0216/540));


		//Loop for data                 
                Long64_t total_data = data->GetEntries();
                // cout<< " total data" << total_data<<'\n'; 
                for (Long64_t ievent_data = 0; ievent_data < total_data; ievent_data++) {
                data->GetEntry(ievent_data);

                //set cut criteria 
                if (!(data_PhotonPt1 >= 10  && data_PhotonPt2 >= 10)) {

                continue;
                }
                if (!(fabs(data_PhotonEta1 < 2.5) && fabs(data_PhotonEta2 < 2.5))) {
                
		continue;
                }		
        	if (!(data_PhotonInvMass >= 200)) {

        	continue;
        	}
                if (!(data_PhotonAcop <= start_DiphotonAcop)) {
                continue;
                }
                ++data_events;
                }

		//Fill to histogram TH1D version
		significance = (double)(MC_events) /sqrt(MC_events + data_events);
		
		//Fill to Tgraph
		significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);

		cout<< " significance = "<< significance <<'\n';
		cout<<" MC_events = " 	<< MC_events	<< " start_DiphotonAcop " << start_DiphotonAcop <<'\n';
		cout<<" data_events = " << data_events	<< " start_DiphotonAcop " << start_DiphotonAcop <<'\n';
		cout<<"  MC_nbins = " <<  MC_nbins <<'\n'; 


		start_DiphotonAcop += 0.002;
		++Tgraph_i;

	}



/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				draw 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/


     	TCanvas *c3 = new TCanvas("c3","c3");
	MC_Acop->SetLineColor(kRed);
	data_Acop->SetLineColor(kBlue);
    	data_Acop->Draw(""); 
	MC_Acop->Draw("sames hist e1");
    	c3->Modified();
    	MC_Acop->SetStats(1111);
    	data_Acop->SetStats(1111);
    	data_Acop->SetTitle("Diphoton acoplanarity"); //This not available in ATLAS.Style
    	MC_Acop->SetTitle("Diphoton acoplanarity"); //This not available in ATLAS.Style
    	MC_Acop->SetName("signalMC");
    	data_Acop->SetName("data");
    	MC_Acop->SetLineWidth(1);
    	data_Acop->SetLineWidth(1);

	gPad->Update();
	//TPaveStats *st1 = (TPaveStats*)MC_Acop->FindObject("stats");
	//st1->SetName("mystats"); //it works whether it is command or not
	//st1->SetShadowColor(0);
	//gPad->Modified();
	//gPad->Update();
  	c3->Update();




/*
	TCanvas *c4 = new TCanvas("c4","c4");
	MC_Pt->Sumw2();
 	MC_Pt->Scale(A2/diphoton->GetEntries());
	MC_Pt->SetLineColor(kRed);
	data_Pt->SetLineColor(kBlue);
    	MC_Pt->Draw("hist e1");
	data_Pt->Draw("sames hist e1");
    	c4->Modified();
    	MC_Pt->SetStats(0);
    	data_Pt->SetStats(1111);
    	//data_Pt->SetTitle("DiphotonPt");
    	MC_Pt->SetName("signalMC");
    	data_Pt->SetName("data");
    	//MC_Pt->SetTitle("DiphotonPt"); This will not be displayed on a TCanvas in ATLAS.Style
    	MC_Pt->SetLineWidth(1);
    	data_Pt->SetLineWidth(1);

	gPad->Update();
	TPaveStats *st2 = (TPaveStats*)data_Pt->FindObject("stats");
	st2->SetName("mystats"); //it works whether it command or not
	st2->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
	c4->Update();




    	TCanvas *c5 = new TCanvas("c5","c5");
 	//MC_Pt_2D->Scale(data_Pt_2D->GetEntries() / MC_Pt_2D->GetEntries());
	MC_Pt_2D->SetMarkerColor(kRed);
	data_Pt_2D->SetMarkerColor(kBlue);
	data_Pt_2D->Draw("");
    	MC_Pt_2D->Draw("sames");
    	c5->Modified();
    	MC_Pt_2D->SetStats(0);
    	data_Pt_2D->SetStats(1111);
	//data_Pt_2D->SetTitle("PhotonPt2:PhotonPt1"); //This will not be displayed on a TCanvas in ATLAS.Style
	MC_Pt_2D->SetName("signalMC");
	data_Pt_2D->SetName("data");

	gPad->Update();
	TPaveStats *st3 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	//st3->SetName("mystats"); //it works whether it command or not
	st3->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
	c5->Update();

*/
  
  	TCanvas *c6 = new TCanvas("c6","c6");
 	//MC_Pt_2D->Scale(data_Pt_2D->GetEntries() / MC_Pt_2D->GetEntries());
	significance_DiphotonAcop->Draw("AP");
    	c6->Modified();
    	//significance_DiphotonAcop->SetStats(0); SetStats object is only for TH1D
	//significan_DiphotonAcop->SetTitle("PhotonPt2:PhotonPt1");
	//significan_DiphotonAcop->SetName("signalMC");

	//gPad->Update();
	//TPaveStats *st6 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	//st6->SetName("mystats"); //it works whether it is command or not
	//st6->SetShadowColor(0);
	//gPad->Modified();
	//gPad->Update();
	//c6->Update();


//	outputFile->Close();


return 0;

}	
