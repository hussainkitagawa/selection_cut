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
	TFile *file1 = new TFile("/Users/kitagawa/analysis_ALP/diphoton.root"); //default is "read" option
	TFile *file2 = new TFile("/Users/kitagawa/analysis_ALP/data.root"); 

	// obtain tree
	TTree* diphoton = (TTree*)file1->Get("diphoton");
	TTree* data = (TTree*)file2->Get("TreePhoton");




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


	// Set output file
        TFile* outputFile_1 = new TFile("data_MC.root", "recreate");
        TTree* outputTree_1 = new TTree("diphoton", "diphoton");


	//Set outpot Branches	
/*	bool  MC_fPhotonSelected1 = 0;
	bool  MC_fPhotonSelected2 = 0;
	bool  MC_fPhotonSelectEta1 = 0;
	bool  MC_fPhotonSelectAuthor1 = 0;
	bool  MC_fPhotonSelectCluster1 = 0;
	bool  MC_fPhotonSelectCleaning1 = 0;	
	unsigned int  MC_fPhotonSelectTightBitmap1 = 0;
	bool  MC_fPhotonSelectEta2 = 0;
	bool  MC_fPhotonSelectAuthor2 = 0;
	bool  MC_fPhotonSelectCluster2 = 0;	
	bool  MC_fPhotonSelectCleaning2 = 0;
	bool  MC_fPhotonSelectTight2 = 0;	
	unsigned int  MC_fPhotonSelectTightBitmap2 = 0;
*/	double  MC_fPhotonPt1 = 0;		
	double  MC_fPhotonEta1 = 0;	
	double  MC_fPhotonPhi1 = 0;
	double  MC_fPhotonE1 = 0;
	double  MC_fPhotonPt2 = 0;			
	double  MC_fPhotonEta2 = 0;		
	double  MC_fPhotonPhi2 = 0;	
	double  MC_fPhotonE2 = 0;		
	double  MC_fDiphotonPt = 0;			
	double  MC_fDiphotonEta = 0;		
	double  MC_fDiphotonPhi = 0;			
	double  MC_fDiphotonE = 0;			
	double  MC_fDiphotonM = 0;			
	double  MC_fDiphotonAcop = 0;		
	double  MC_fDiphotonY = 0;			
	double  MC_fDiphotonXiA = 0;			
	double  MC_fDiphotonXiC = 0;			
	double  MC_fTruthPhotonPt1 = 0;		
	double  MC_fTruthPhotonEta1 = 0;		
	double  MC_fTruthPhotonPhi1 = 0;		
	double  MC_fTruthPhotonE1 = 0;		
	double  MC_fTruthPhotonPt2 = 0;		
	double  MC_fTruthPhotonEta2 = 0;		
	double  MC_fTruthPhotonPhi2 = 0;	
	double  MC_fTruthPhotonE2 = 0;		
	double  MC_fTruthDiphotonPt = 0;		
	double  MC_fTruthDiphotonEta = 0;	
	double  MC_fTruthDiphotonPhi = 0;	
	double  MC_fTruthDiphotonE = 0;	
	double  MC_fTruthDiphotonM = 0;	
	double  MC_fTruthDiphotonAcop = 0;	
	double  MC_fTruthDiphotonY = 0;	
	double  MC_fTruthDiphotonXiA = 0;	
	double  MC_fTruthDiphotonXiC = 0;	
	double  MC_fPhotonDeltaR1 = 0;	
	double  MC_fPhotonDeltaR2 = 0;	
/*  	outputTree->Branch("MC_PhotonSelected1",		&MC_fPhotonSelected1);
  	outputTree->Branch("MC_PhotonSelected2",		&MC_fPhotonSelected2);
  	outputTree->Branch("MC_PhotonSelectEta1",		&MC_fPhotonSelectEta1);
  	outputTree->Branch("MC_PhotonSelectAuthor1",		&MC_fPhotonSelectAuthor1);
  	outputTree->Branch("MC_PhotonSelectCluster1",		&MC_fPhotonSelectCluster1);
  	outputTree->Branch("MC_PhotonSelectCleaning1",		&MC_fPhotonSelectCleaning1);
  	outputTree->Branch("MC_PhotonSelectTight1",		&MC_fPhotonSelectTight1);
  	outputTree->Branch("MC_PhotonSelectTightBitmap1",	&MC_fPhotonSelectTightBitmap1);
  	outputTree->Branch("MC_PhotonSelectEta2",		&MC_fPhotonSelectEta2);
  	outputTree->Branch("MC_PhotonSelectAuthor2",		&MC_fPhotonSelectAuthor2);
  	outputTree->Branch("MC_PhotonSelectCluster2",		&MC_fPhotonSelectCluster2);
  	outputTree->Branch("MC_PhotonSelectCleaning2",		&MC_fPhotonSelectCleaning2);
  	outputTree->Branch("MC_PhotonSelectTight2",		&MC_fPhotonSelectTight2);
  	outputTree->Branch("MC_PhotonSelectTightBitmap2",	&MC_fPhotonSelectTightBitmap2);
*/  	outputTree_1->Branch("MC_PhotonPt1",			&MC_fPhotonPt1);
  	outputTree_1->Branch("MC_PhotonEta1",			&MC_fPhotonEta1);
  	outputTree_1->Branch("MC_PhotonPhi1",			&MC_fPhotonPhi1);
  	outputTree_1->Branch("MC_PhotonE1",			&MC_fPhotonE1);
  	outputTree_1->Branch("MC_PhotonPt2",			&MC_fPhotonPt2);
  	outputTree_1->Branch("MC_PhotonEta2",			&MC_fPhotonEta2);
  	outputTree_1->Branch("MC_PhotonPhi2",			&MC_fPhotonPhi2);
  	outputTree_1->Branch("MC_PhotonE2",			&MC_fPhotonE2);
  	outputTree_1->Branch("MC_DiphotonPt",			&MC_fDiphotonPt);
  	outputTree_1->Branch("MC_DiphotonEta",			&MC_fDiphotonEta);
  	outputTree_1->Branch("MC_DiphotonPhi",			&MC_fDiphotonPhi);
  	outputTree_1->Branch("MC_DiphotonE",			&MC_fDiphotonE);
  	outputTree_1->Branch("MC_DiphotonM",			&MC_fDiphotonM);
  	outputTree_1->Branch("MC_DiphotonAcop",			&MC_fDiphotonAcop);
  	outputTree_1->Branch("MC_DiphotonY",			&MC_fDiphotonY);
  	outputTree_1->Branch("MC_DiphotonXiA",			&MC_fDiphotonXiA);
  	outputTree_1->Branch("MC_DiphotonXiC",			&MC_fDiphotonXiC);
  	outputTree_1->Branch("MC_TruthPhotonPt1",		&MC_fTruthPhotonPt1);
  	outputTree_1->Branch("MC_TruthPhotonEta1",		&MC_fTruthPhotonEta1);
  	outputTree_1->Branch("MC_TruthPhotonPhi1",		&MC_fTruthPhotonPhi1);
  	outputTree_1->Branch("MC_TruthPhotonE1",		&MC_fTruthPhotonE1);
  	outputTree_1->Branch("MC_TruthPhotonPt2",		&MC_fTruthPhotonPt2);
  	outputTree_1->Branch("MC_TruthPhotonEta2",		&MC_fTruthPhotonEta2);
  	outputTree_1->Branch("MC_TruthPhotonPhi2",		&MC_fTruthPhotonPhi2);
  	outputTree_1->Branch("MC_TruthPhotonE2",		&MC_fTruthPhotonE2); 
  	outputTree_1->Branch("MC_TruthDiphotonPt",		&MC_fTruthDiphotonPt);
  	outputTree_1->Branch("MC_TruthDiphotonEta",		&MC_fTruthDiphotonEta);
  	outputTree_1->Branch("MC_TruthDiphotonPhi",		&MC_fTruthDiphotonPhi);
  	outputTree_1->Branch("MC_TruthDiphotonE",		&MC_fTruthDiphotonE);
  	outputTree_1->Branch("MC_TruthDiphotonM",		&MC_fTruthDiphotonM);
  	outputTree_1->Branch("MC_TruthDiphotonAcop",		&MC_fTruthDiphotonAcop);
  	outputTree_1->Branch("MC_TruthDiphotonY",		&MC_fTruthDiphotonY);
  	outputTree_1->Branch("MC_TruthDiphotonXiA",		&MC_fTruthDiphotonXiA);
  	outputTree_1->Branch("MC_TruthDiphotonXiC",		&MC_fTruthDiphotonXiC);
  	outputTree_1->Branch("MC_PhotonDeltaR1",		&MC_fPhotonDeltaR1);
  	outputTree_1->Branch("MC_PhotonDeltaR2",		&MC_fPhotonDeltaR2);






	/*    histogram of Acoplanarity    */
      	TH1D *MC_Acop = new TH1D("", "", 100, 0, 0.02);//0.018
      	MC_Acop->SetTitle(" 	;  DiphotonAcop;");
      	//hist1->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();

      	TH1D *MC_Pt = new TH1D("", "", 100, 0, 250);
      	MC_Pt->SetTitle("	;  DiphotonPt;");
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
	int MC_selected_event = 0;
 	std::cout<< "Total events of MC   = "<< MC_total <<'\n';

  	for (int event = 0; event<MC_total; event++) {
	diphoton->GetEntry(event);	

	// Fill values to output branch	
/*  	MC_fPhotonSelected1		=	MC_PhotonSelected1;
  	MC_fPhotonSelected2		=	MC_PhotonSelected2;
  	MC_fPhotonSelectEta1		=	MC_PhotonSelectEta1;
  	MC_fPhotonSelectAuthor1		=	MC_PhotonSelectAuthor1;
  	MC_fPhotonSelectCluster1	=	MC_PhotonSelectCluster1;
  	MC_fPhotonSelectCleaning1	=	MC_PhotonSelectCleaning1;	
  	MC_fPhotonSelectTightBitmap1	=	MC_PhotonSelectTightBitmap1;
  	MC_fPhotonSelectEta2		=	MC_PhotonSelectEta2;
  	MC_fPhotonSelectAuthor2		=	MC_PhotonSelectAuthor2;
  	MC_fPhotonSelectCluster2	=	MC_PhotonSelectCluster2;	
  	MC_fPhotonSelectCleaning2	=	MC_PhotonSelectCleaning2;
  	MC_fPhotonSelectTight2		=	MC_PhotonSelectTight2;	
  	MC_fPhotonSelectTightBitmap2	=	MC_PhotonSelectTightBitmap2;
*/  	MC_fPhotonPt1			=	MC_PhotonPt1;		
  	MC_fPhotonEta1			=	MC_PhotonEta1;	
  	MC_fPhotonPhi1			=	MC_PhotonPhi1;
  	MC_fPhotonE1			=	MC_PhotonE1;
  	MC_fPhotonPt2			=	MC_PhotonPt2;			
  	MC_fPhotonEta2			=	MC_PhotonEta2;		
  	MC_fPhotonPhi2			=	MC_PhotonPhi2;	
  	MC_fPhotonE2			=	MC_PhotonE2;		
  	MC_fDiphotonPt			=	MC_DiphotonPt;			
  	MC_fDiphotonEta			=	MC_DiphotonEta;		
  	MC_fDiphotonPhi			=	MC_DiphotonPhi;			
  	MC_fDiphotonE			=	MC_DiphotonE;			
  	MC_fDiphotonM			=	MC_DiphotonM;			
  	MC_fDiphotonAcop		=	MC_DiphotonAcop;		
  	MC_fDiphotonY			=	MC_DiphotonY;			
  	MC_fDiphotonXiA			=	MC_DiphotonXiA;			
  	MC_fDiphotonXiC			=	MC_DiphotonXiC ;			
  	MC_fTruthPhotonPt1		=	MC_TruthPhotonPt1;		
  	MC_fTruthPhotonEta1		=	MC_TruthPhotonEta1;		
  	MC_fTruthPhotonPhi1		=	MC_TruthPhotonPhi1;		
  	MC_fTruthPhotonE1		=	MC_TruthPhotonE1;		
  	MC_fTruthPhotonPt2		=	MC_TruthPhotonPt2;		
  	MC_fTruthPhotonEta2		=	MC_TruthPhotonEta2;		
  	MC_fTruthPhotonPhi2		=	MC_TruthPhotonPhi2;	
  	MC_fTruthPhotonE2		=	MC_TruthPhotonE2;		
  	MC_fTruthDiphotonPt		=	MC_TruthDiphotonPt;		
  	MC_fTruthDiphotonEta		=	MC_TruthDiphotonEta;	
  	MC_fTruthDiphotonPhi		=	MC_TruthDiphotonPhi;	
  	MC_fTruthDiphotonE		=	MC_TruthDiphotonE;	
  	MC_fTruthDiphotonM		=	MC_TruthDiphotonM;	
  	MC_fTruthDiphotonAcop		=	MC_TruthDiphotonAcop;	
  	MC_fTruthDiphotonY		=	MC_TruthDiphotonY;	
  	MC_fTruthDiphotonXiA		=	MC_TruthDiphotonXiA;	
  	MC_fTruthDiphotonXiC		=	MC_TruthDiphotonXiC;	
  	MC_fPhotonDeltaR1		=	MC_PhotonDeltaR1;	
  	MC_fPhotonDeltaR2		=	MC_PhotonDeltaR2;	

	
	MC_selected_event++;

    	MC_Acop->Fill(MC_DiphotonAcop);
      	MC_Pt->Fill(MC_DiphotonPt);
	MC_Pt_2D->Fill(MC_PhotonPt1, MC_PhotonPt2);

	outputTree_1->Fill();
	}

	std::cout<< "Selected events of MC  = " << MC_selected_event << '\n';


	//Save above branches to TTree
        outputTree_1->Write();




/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				data 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/

	//Createa a another TTree to the output file
        TTree* outputTree_2 = new TTree("TreePhoton", "TreePhoton");



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



	//Add Brches of data to output file 
  	UInt_t data_fRunNumber = 0;
	ULong64_t data_fEventNumber = 0;
	UInt_t data_fLumiBlock = 0;
  	double data_fPhotonAcop = 0;
	double data_fPhotonPt1= 0;
	double data_fPhotonPt2= 0;
	double data_fPhotonPhi1= 0;
	double data_fPhotonPhi2= 0;
	double data_fPhotonEta1= 0;
	double data_fPhotonEta2= 0;
	double data_fPhotonE1= 0;
	double data_fPhotonE2= 0;
	double data_fPhotonY= 0;
	double data_fPhotonPt= 0;
	double data_fPhotonXiA= 0;
	double data_fPhotonXiC= 0;
	double data_fPhotonInvMass = 0;
	double data_fPhotonTrkPt = 0;
  	outputTree_2->Branch("data_RunNumber",		&data_fRunNumber);
  	outputTree_2->Branch("data_EventNumber",	&data_fEventNumber);
  	outputTree_2->Branch("data_LumiBlock",		&data_fLumiBlock);
  	outputTree_2->Branch("data_PhotonAcop",		&data_fPhotonAcop);
  	outputTree_2->Branch("data_PhotonPt1",		&data_fPhotonPt1);
  	outputTree_2->Branch("data_PhotonPt2",		&data_fPhotonPt2);
  	outputTree_2->Branch("data_PhotonPhi1",		&data_fPhotonPhi1);
  	outputTree_2->Branch("data_PhotonPhi2",		&data_fPhotonPhi2);
  	outputTree_2->Branch("data_PhotonEta1",		&data_fPhotonEta1);
  	outputTree_2->Branch("data_PhotonEta2",		&data_fPhotonEta2);
  	outputTree_2->Branch("data_PhotonE1",		&data_fPhotonE1);
  	outputTree_2->Branch("data_PhotonE2",		&data_fPhotonE2);
  	outputTree_2->Branch("data_PhotonY",		&data_fPhotonY);
  	outputTree_2->Branch("data_PhotonPt",		&data_fPhotonPt);
  	outputTree_2->Branch("data_PhotonXiA",		&data_fPhotonXiA);
  	outputTree_2->Branch("data_PhotonXiC",		&data_fPhotonXiC);
  	outputTree_2->Branch("data_PhotonInvMass",	&data_fPhotonInvMass);
  	outputTree_2->Branch("data_PhotonTrkPt",	&data_fPhotonTrkPt);



	/*    histogram of Acoplanarity    */
      	TH1D *data_Acop = new TH1D("", "", 100, 0, 0.02);
      	data_Acop->SetTitle(" 	;  DiphotonAcop;");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();

      	TH1D *data_Pt = new TH1D("", "", 880, 0, 2200);
      	data_Pt->SetTitle(";	DiphotonPt; ");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);
      	//hist2->GetYaxis()->CenterTitle();

      	TH2D *data_Pt_2D = new TH2D("", "", 100, 0, 2200, 100, 0, 1000);//1000 is for Pt2
      	data_Pt_2D->SetTitle(" ; PhotonPt1; PhotonPt2");
      	//hist2->GetXaxis()->CenterTitle();
      	//hist2->GetYaxis()->SetTitleOffset(1.2);




	/**********	Start main loop of data	(data.root)	**********/
  	Long64_t data_total = data->GetEntries();  // total number of events
	long int data_selected_event = 0;
 	std::cout<< "Total events of data  = "<< data_total <<'\n';

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
	// Fill values to output branch
        data_fRunNumber      =       data_RunNumber;
        data_fEventNumber    =       data_EventNumber;
        data_fLumiBlock      =       data_LumiBlock;
        data_fPhotonAcop     =       data_PhotonAcop;
        data_fPhotonPt1      =       data_PhotonPt1;
        data_fPhotonPt2      =       data_PhotonPt2;
        data_fPhotonPhi1     =       data_PhotonPhi1;
        data_fPhotonPhi2     =       data_PhotonPhi2;
        data_fPhotonEta1     =       data_PhotonEta1;
        data_fPhotonEta2     =       data_PhotonEta2;
        data_fPhotonE1       =       data_PhotonE1;
        data_fPhotonE2       =       data_PhotonE2;
        data_fPhotonY        =       data_PhotonY;
        data_fPhotonPt       =       data_PhotonPt;
        data_fPhotonXiA      =       data_PhotonXiA;
        data_fPhotonXiC      =       data_PhotonXiC;
        data_fPhotonInvMass  =       data_PhotonInvMass;
        data_fPhotonTrkPt    =       data_PhotonTrkPt;
	
	data_selected_event++;

      	data_Acop->Fill(data_PhotonAcop);
      	data_Pt->Fill(data_PhotonPt);
	data_Pt_2D->Fill(data_PhotonPt1, data_PhotonPt2);

	outputTree_2->Fill();
	
//	if (data_selected_event == 10000) {
//	break;
//	}


	} //Loop end
	std::cout<< "Selected events of data  = " << data_selected_event << '\n';

	//Save TTree to output file
	outputTree_2->Write();






/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				draw 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/

     	TCanvas *c1 = new TCanvas("c1","c1");
	MC_Acop->Sumw2();
    	MC_Acop->Scale(data_Acop->Integral() / MC_Acop->Integral());
	MC_Acop->SetLineColor(kRed);
	data_Acop->SetLineColor(kBlue);
	MC_Acop->Draw("hist e1");
    	data_Acop->Draw("sames hist e1");
    	c1->Modified();
    	MC_Acop->SetStats(0);
    	data_Acop->SetStats(1111);
    	//data_Acop->SetTitle("Diphoton acoplanarity");
    	//MC_Acop->SetTitle("Diphoton acoplanarity");
    	//MC_Acop->SetName("signalMC");
    	data_Acop->SetName("data");
    	MC_Acop->SetLineWidth(1);
    	data_Acop->SetLineWidth(1);

	gPad->Update();
	TPaveStats *st1 = (TPaveStats*)data_Acop->FindObject("stats");
	st1->SetName("mystats"); //it works whether it command or not
	st1->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
  	c1->Update();





	TCanvas *c2 = new TCanvas("c2","c2");
	MC_Pt->Sumw2();
 	MC_Pt->Scale(data_Pt->Integral() / MC_Pt->Integral());
	MC_Pt->SetLineColor(kRed);
	data_Pt->SetLineColor(kBlue);
	data_Pt->Draw("hist e1");
    	MC_Pt->Draw("sames hist e1");
    	c2->Modified();
    	MC_Pt->SetStats(0);
    	data_Pt->SetStats(1111);
    	//data_Pt->SetTitle("DiphotonPt");
    	MC_Pt->SetName("signalMC");
    	data_Pt->SetName("data");
    	//MC_Pt->SetTitle("DiphotonPt"); This will not displayed on TCanvas
    	MC_Pt->SetLineWidth(1);
    	data_Pt->SetLineWidth(1);

	gPad->Update();
	TPaveStats *st2 = (TPaveStats*)data_Pt->FindObject("stats");
	st2->SetName("mystats"); //it works whether it command or not
	st2->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
	c2->Update();




    	TCanvas *c3 = new TCanvas("c3","c3");
 	//MC_Pt_2D->Scale(data_Pt_2D->GetEntries() / MC_Pt_2D->GetEntries());
	MC_Pt_2D->SetMarkerColor(kRed);
	data_Pt_2D->SetMarkerColor(kBlue);
	data_Pt_2D->Draw("");
    	MC_Pt_2D->Draw("sames");
    	c3->Modified();
    	MC_Pt_2D->SetStats(0);
    	data_Pt_2D->SetStats(1111);
	//data_Pt_2D->SetTitle("PhotonPt2:PhotonPt1");
	MC_Pt_2D->SetName("signalMC");
	data_Pt_2D->SetName("data");

	gPad->Update();
	TPaveStats *st3 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	st3->SetName("mystats"); //it works whether it command or not
	st3->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
	c3->Update();




//	outputFile_1->Close();
//	outputFile_2->Close();



return 0;

}	
