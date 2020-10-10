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
//#include "AtlasStyle.C"
//#include "AtlasLabels.C"

int data_signal(){

	// obtain rootfile
	TFile *file1 = new TFile("/Users/kitagawa/analysis_ALP/diphoton.root");
	TFile *file2 = new TFile("/Users/kitagawa/analysis_ALP/data.root");

	// obtain tree
	TTree* diphoton = (TTree*)file1->Get("diphoton");
	TTree* data = (TTree*)file2->Get("TreePhoton");

	//Set branch Address
	double DiphotonPt, TruthDiphotonPt;//signalMc
	double PhotonAcop; //data
	diphoton->SetBranchAddress("DiphotonPt", &DiphotonPt);
	diphoton->SetBranchAddress("TruthDiphotonPt", &TruthDiphotonPt);
	data->SetBranchAddress("PhotonAcop", &PhotonAcop);


	/*    histogram of Acoplanarity    */
      	TH1D *hist1 = new TH1D("", "", 100, 0, 20);
      	//hist1->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();

      	TH1D *hist2 = new TH1D("", "", 100, 0, 20);
      	//hist2->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);
      	//hist2->GetYaxis()->CenterTitle();

      	TH1D *hist3 = new TH1D("", "", 100, 0, 1);
      	//hist2->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);



	/*   Initital parameters   */
  	int total = diphoton->GetEntries();  // total number of events
 	std::cout<< "Total events = "<< total <<'\n';


	/*	main loop	*/
  	for (int event = 0; event<total; event++) {
      	diphoton->GetEntry(event);
      	//std::cout<<" ****** Event = " << event <<" ******\n";
      	hist1->Fill(DiphotonPt);
      	hist2->Fill(TruthDiphotonPt);
	}

	/*	main loop	*/
  	int data_total = data->GetEntries();  // total number of events
 	std::cout<< "Total events = "<< data_total <<'\n';

  	for (int ievent = 0; ievent<1000; ievent++) {
      	data->GetEntry(ievent);
      	//std::cout<<" ****** Event = " << ievent <<" ******\n";
      	hist3->Fill(PhotonAcop);
	}


	//output file
	//TFile *fout = new TFile("./result_file/histo/decay_curve.root","recreate");


	// Draw 
      	TCanvas *c1 = new TCanvas("c1","c1");
    	c1->cd();
    	hist2->Draw();
    	hist1->Draw("sames");

    	c1->Modified();
    	hist1->SetStats();
    	hist2->SetStats();
    	hist1->SetLineWidth(1);
    	hist2->SetLineWidth(1);
    	hist2->SetLineColor(kRed);
    	//hist1->SetTitle("; time [nsec]; Number of events [/120nsec]");
    	c1->Update();
/*
	TCanvas *c2 = new TCanvas("c2","c2");
    	hist2->Draw();
    	hist3->Draw("sames");

    	c2->Modified();
    	hist2->SetStats(0);
    	hist3->SetStats(0);
    	hist2->SetLineWidth(1);
    	hist3->SetLineWidth(1);
    	hist2->SetLineColor(kRed);
  */  	//hist1->SetTitle("; time [nsec]; Number of events [/120nsec]");
    //	c2->Update();

//	TCanvas *c3 = new TCanvas("c3","c3");
//	hist3->Draw();
	//c1->Write();
	//c1->SaveAs("./pdf/10000_events/respectively/decay_curve.pdf");
	//fout->Close ();

return 0;
}	
