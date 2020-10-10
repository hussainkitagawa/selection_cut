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
	TFile *file3 = new TFile("/Users/kitagawa/analysis_ALP/Tomas/convert_CSV_ROOT/ALP_GeneratorMC.root");

	// obtain tree
	TTree* diphoton	= (TTree*)file1->Get("diphoton");
	TTree* data	= (TTree*)file2->Get("TreePhoton");	
        TTree* tree	 = (TTree*)file3->Get("alp_200GeV");

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



	//histogram of Acoplanarity    
      	TH1D *MC_Acop = new TH1D("", "", 540, 0, 0.0216);
      	MC_Acop->SetTitle(" ;  DiphotonAcop; Events");
      	//hist1->SetTitle("Muon Lifetime ; time [nsec]; Number of events [/120nsec]");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();





	//Start main Loop of MC (diphoton.root)
  	int MC_total = diphoton->GetEntries(); 
 	cout<< " Total events of signalMC   = "<< MC_total <<'\n';
	double max_Acop;
	double MC_pass = 0;

  	for (int event = 0; event<MC_total; event++) {
		diphoton->GetEntry(event);	
		//Calculation of maximum acoplanarity
		if (max_Acop <  MC_TruthDiphotonAcop){
		
		max_Acop = MC_TruthDiphotonAcop;		
		}


		// Fill values to output branch	
		if (!(MC_TruthDiphotonAcop <= 0.02)) {

		continue;
		}

    		MC_Acop->Fill(MC_TruthDiphotonAcop);
		
		//MC_pass++;
		//if(MC_pass == 5000){
		//break;
		//}

	}

	std::cout<< " max_MC_Acop = "<< max_Acop;
	std::cout<< " MC_selected  = " << MC_pass << '\n';

/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*		  	 Generator level 			*/
/*			(ALP mass 200GeV)		 	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/

	//Set branch Address	
	double Energy_ALP;
	double Energy_Photon1;
	double Energy_Photon2;
	double Mass_ALP;
	double Mass_Photon1;
	double Mass_Photon2;
	double Theta_Photon1;
	double Theta_Photon2;
	double Eta_Photon1;
	double Eta_Photon2;
	double TransverseMomentum_Photon1;
	double TransverseMomentum_Photon2;
	double DiphotonAcoplanarity;
	tree->SetBranchAddress("200GeV_Energy_ALP", 	&Energy_ALP);
	tree->SetBranchAddress("200GeV_Energy_Photon1", &Energy_Photon1);
	tree->SetBranchAddress("200GeV_Energy_Photon2", &Energy_Photon2);
	tree->SetBranchAddress("200GeV_Mass_ALP", 	&Mass_ALP);
	tree->SetBranchAddress("200GeV_Mass_Photon1", 	&Mass_Photon1);
	tree->SetBranchAddress("200GeV_Mass_Photon2", 	&Mass_Photon2);
	tree->SetBranchAddress("200GeV_Theta_Photon1", 	&Theta_Photon1);
	tree->SetBranchAddress("200GeV_Theta_Photon2", 	&Theta_Photon2);
	tree->SetBranchAddress("200GeV_Eta_Photon1", 	&Eta_Photon1);
	tree->SetBranchAddress("200GeV_Eta_Photon2", 	&Eta_Photon2);
	tree->SetBranchAddress("200GeV_TransverseMomentum_Photon1", 	&TransverseMomentum_Photon1);
	tree->SetBranchAddress("200GeV_TransverseMomentum_Photon2", 	&TransverseMomentum_Photon2);
	tree->SetBranchAddress("200GeV_Acoplanarity", 	&DiphotonAcoplanarity);
		



	//histogram of Acoplanarity  
	//TH1D* Generator_Acop_200GeV= new TH1D("", "", 540, 0, 0.0216);
	TH1D* GeneratorMC_Acop = new TH1D("", "", 300, 0, 0.012);



        /**********   Start main Loop of Generator level with 200 GeV ALP mass(ALP_GeneratorMC.root)   **********/
	double maximum_Acop = 0;
	int GeneratorMC_selected = 0;
	int GeneratorMC_pass = 0;
	double acoplanarity = 0.01;
       	Long64_t GeneratorMC_total = tree->GetEntries();		
cout<<"GeneratorMC_total = "<<GeneratorMC_total<<endl;
        for (Long64_t ievent = 0; ievent <  GeneratorMC_total; ievent++) {
       		tree->GetEntry(ievent);
		

		//Calculation of maximum acoplanarity
             	if (maximum_Acop < DiphotonAcoplanarity){
              	maximum_Acop = DiphotonAcoplanarity;
               	}

		//Preselction
		if(-1.52 < Eta_Photon1  && Eta_Photon1 < -1.137){
		continue;
		}
		if(1.37 < Eta_Photon1  && Eta_Photon1 < 1.52){
		continue;
		}
		if(!(-2.37 < Eta_Photon1 && Eta_Photon1 < 2.37)){
		continue;
		}
		if(-1.52 < Eta_Photon2  && Eta_Photon2 < -1.137){
		continue;
		}
		if(1.37 < Eta_Photon2  && Eta_Photon2 < 1.52){
		continue;
		}
		if(!(-2.37 < Eta_Photon2 && Eta_Photon2 < 2.37)){
		continue;
		}
		if(!(10 < TransverseMomentum_Photon1)){
		continue;
		}
		if(!(10 < TransverseMomentum_Photon2)){
		continue;
		}
	
		GeneratorMC_selected++;

		//Arbitrary selction by user		
        	if(!(DiphotonAcoplanarity <= acoplanarity)){
		continue;
		}
		

		GeneratorMC_Acop->Fill(DiphotonAcoplanarity);
		GeneratorMC_pass++;
       	}

	cout<< "maximum_Acop" <<  maximum_Acop << endl;	
	cout<< "GeneratorMC_selected" <<  GeneratorMC_selected << endl;	
	cout<< "GeneratorMC_pass" <<   GeneratorMC_pass << endl;	


/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*				data 	                	*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/
/*

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


	///histogram of Acoplanarity    
	//TH1D *data_Acop = new TH1D("", "", 1, 0, 0.021); //for constant
      	TH1D *data_Acop = new TH1D("", "", 540, 0, 0.0216);
      	data_Acop->SetTitle("Number of events;  DiphotonAcop;");
      	//hist1->GetXaxis()->CenterTitle();
      	//hist1->GetYaxis()->SetTitleOffset(1.2);
      	//hist1->GetYaxis()->CenterTitle();



	//Start main loop of data (data.root)
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
	
//	if (data_selected_event == 10000) {
//	break;
//	}


	} //Loop end
	
	
	
	std::cout<< "Selected events of data  = " << data_selected_event << '\n';

*/
	/********************************/
	/*				*/
	/*	fill constant value 	*/
	/*				*/
	/********************************/
	//assume data(background) is constant
/*	double ktotal = 0.021;
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
	double end_DiphotonAcop = 0.012;
	double start_DiphotonAcop = 0.002;
	//Set parameters for Loop
	long double significance;
	const double plot = end_DiphotonAcop/start_DiphotonAcop;
	int Tgraph_i= 0;
	double bin_size = 0.0216/540;


	//histogram of TGraph
	TGraph *significance_DiphotonAcop = new TGraph(plot); 
      	significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");


	
	while (start_DiphotonAcop <= end_DiphotonAcop) {
		//Set parameters for Loop
		significance = 0;
 		double GeneratorMC_events = 0;
 		double const_data_events = 0;
	

		//Loop for Generator level			
		Long64_t total_GeneratorMC = tree->GetEntries(); 
		cout<< " total GeneratorMC" << total_GeneratorMC<< '\n';
		for (Long64_t i = 0; i < total_MC; i++) {
			tree->GetEntry(i);
        		if (MC_DiphotonAcop <= start_DiphotonAcop) {
			++GeneratorMC_events;
			}
			else;
		}	

		const_data_events = 3000 * (start_DiphotonAcop / bin_size);

		//Fill to histogram TH1D version
		significance = (double)(GeneratorMC_events) /sqrt(GeneratorMC_events + const_data_events);
		
		//Fill to Tgraph
		significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);

		cout<< " significance = "<< significance <<'\n';
		cout<< " start_DiphotonAcop = " << start_DiphotonAcop
		cout<<" GeneratorMC_events = " 	<< GeneratorMC_events << endl;	
		cout<<" const_data_events = " << const_data_events<< endl; 

		cout<<'\n';
		cout<<'\n';
		cout<<'\n';

		start_DiphotonAcop += 0.002;
		++Tgraph_i;

	}






*/

/****************************************************************/
/*                                                              */
/*      		Significance				*/
/*                                                              */
/*		events of signalMC are rescaled 		*/
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/


	/****************************************/
	/*					*/
	/*	Rescale events of sinalMC	*/
	/*					*/
	/****************************************/

	//histogram of Acoplanarity    
      	TH1D *MC_Acop_all = new TH1D("", "", 540, 0, 0.0216);


	//Preselection of GeneratorMC
  	for (int event = 0; event < GeneratorMC_total; event++) {
		tree->GetEntry(event);	

		//Preselction
		if(-1.52 < Eta_Photon1  && Eta_Photon1 < -1.137){
		continue;
		}
		if(1.37 < Eta_Photon1  && Eta_Photon1 < 1.52){
		continue;
		}
		if(!(-2.37 < Eta_Photon1 && Eta_Photon1 < 2.37)){
		continue;
		}
		if(-1.52 < Eta_Photon2  && Eta_Photon2 < -1.137){
		continue;
		}
		if(1.37 < Eta_Photon2  && Eta_Photon2 < 1.52){
		continue;
		}
		if(!(-2.37 < Eta_Photon2 && Eta_Photon2 < 2.37)){
		continue;
		}
		if(!(10 < TransverseMomentum_Photon1)){
		continue;
		}
		if(!(10 < TransverseMomentum_Photon2)){
		continue;
		}

		if (!(DiphotonAcoplanarity <= 0.02)) {

		continue;
		}

    		MC_Acop_all->Fill(DiphotonAcoplanarity);
	}

	GeneratorMC_Acop->Sumw2();// Sumw2 has to be done before Scale()
	double luminosity = 32;
	double cross_section = 6.0821;
	double original_GeneratorMC_event = 5000;
	double detecting_efficiency = GeneratorMC_selected / original_GeneratorMC_event;
	long double real = luminosity * cross_section * detecting_efficiency; // expected detectable signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
	cout << " real = " << real <<'\n';
	MC_Acop_all->Scale(real/GeneratorMC_selected);
	double bin_size = 0.0216/540;
	double A1  = acoplanarity/bin_size;//250
	double A4 = MC_Acop_all->Integral(0, A1);
	cout << " events between 0 and 0.01 = " << A4 << endl;
	GeneratorMC_Acop->Scale(A4/GeneratorMC_pass);


	/****************************************/
	/*					*/
	/*	Calculation of significance	*/
	/*					*/
	/****************************************/
	
	

	//Set parameters for Loop
	int Tgraph_i= 0;
	double MC_ibin;

	//histogram of TGraph :: Calculate significance for each ALP mass from 200GeV to 1000GeV with 100GeV increment
	//Set range of DiphotonAcop
	double end_DiphotonAcop = 0.01;
	double start_DiphotonAcop = 0.002;
	
	//Set parameters for Loop
	long double significance;
	const double Nplot = end_DiphotonAcop/start_DiphotonAcop;
	
	TGraph* significance_DiphotonAcop = new TGraph(Nplot); 
      	significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");

	
	while (start_DiphotonAcop <= end_DiphotonAcop) {
		//Set parameters for Loop
		significance = 0;
 		double MC_events = 0;
 		double data_events = 0;
	

		/////  Pattern 1 /////
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
		

		////  Pattern 2 ////
		MC_ibin = start_DiphotonAcop/bin_size;
		MC_events = GeneratorMC_Acop->Integral(0, MC_ibin);
		data_events = 200 * MC_ibin;//background is constant

		significance = (double)(MC_events) /sqrt(MC_events + data_events);
		
		//Fill to Tgraph
		significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);

		cout<<" significance = "<< significance <<'\n';
		cout<<" MC_events    = "<< MC_events	<< '\n';
		cout<<" data_events  = "<< data_events	<< '\n';
		cout<<" MC_ibin     = "<<  MC_ibin <<'\n'; 


		start_DiphotonAcop += 0.002;
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

	//Significance
	TCanvas *c1 = new TCanvas("c1", "c1");
	significance_DiphotonAcop->Draw("AP");
    	c1->Modified();
    	//significance_DiphotonAcop[i]->SetStats(0); //SetStats object is only for TH1D
	//significan_DiphotonAcop->SetTitle("PhotonPt2:PhotonPt1");
	//significan_DiphotonAcop->SetName("signalMC");

	//gPad->Update();
	//TPaveStats *st6 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	//st6->SetName("mystats"); //it works whether it is command or not
	//st6->SetShadowColor(0);
	//gPad->Modified();
	//gPad->Update();
	c1->Update();



//	outputFile->Close();


return 0;

}	
