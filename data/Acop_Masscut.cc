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

int Acop_Masscut(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();



	// obtain rootfile
	TFile *file = new TFile("/Users/kitagawa/analysis_ALP/data/TreePhoton.root"); 

	// obtain tree
	TTree* data = (TTree*)file->Get("TreePhoton");


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
      	//TH1D *data_Acop = new TH1D("", "", 54, 0, 0.00216);//binning size 4e-5
      	TH1D *data_Acop = new TH1D("", "", 108, 0, 0.00216);//binning size 2e-5
      	data_Acop->SetTitle("; DiphotonAcop; Events");



	/**********	Start main loop of data	(TreePhoton.root)	**********/
  	Long64_t total = data->GetEntries();  // total number of events
	Long64_t ievent;
 
  	for (ievent = 0; ievent <  total; ievent++) {
      		data->GetEntry(ievent);
		//set cut criteria 
        	if (!(data_PhotonPt1 >= 10  && data_PhotonPt2 >= 10)) {

        	continue;
        	}
        	if (!(data_PhotonAcop <= 0.002)) {

        	continue;
        	}
        	if (!(fabs(data_PhotonEta1 < 2.5) && fabs(data_PhotonEta2 < 2.5))) {

        	continue;
		}
        	if (!(data_PhotonInvMass >= 200)) {

        	continue;
        }
	
      	data_Acop->Fill(data_PhotonAcop);

	
//	if (data_selected_event == 10000) {
//	break;
//	}


	} //Loop end


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
    	data_Acop->Draw("");
    	c1->Modified();
    	data_Acop->SetStats(1111);
	data_Acop->SetLineColor(kBlue);
    	//data_Acop->SetTitle("Diphoton acoplanarity"); //This not available in ATLAS.Style
    	//MC_Acop->SetTitle("Diphoton acoplanarity"); //This not available in ATLAS.Style
    	//MC_Acop->SetName("signalMC");
    	data_Acop->SetName("data");
    	data_Acop->SetLineWidth(1);

	gPad->Update();
	TPaveStats *st1 = (TPaveStats*)data_Acop->FindObject("stats");
	//st1->SetName("mystats"); //it works whether it is command or not
	st1->SetShadowColor(0);
	gPad->Modified();
	gPad->Update();
  	c1->Update();
	
	//Fitting fucntion
/*	gStyle->SetOptFit(1111);
	TF1 *f1 = new TF1("f2", "[0]*x+[1]", -1., 1.);
	f1->SetParameters(1.2, 90.);
	f1->SetLineColor(2);
	data_Acop->Fit("f2");
*/
cout<<"tanaka to kitagawa = T2K experiment"<<endl;
return 0;

}	
