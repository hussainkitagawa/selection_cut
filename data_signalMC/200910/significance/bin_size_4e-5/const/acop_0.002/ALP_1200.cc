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

void ALP_1200(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();
	


	// obtain rootfile
	TFile *file = new TFile("/Users/kitagawa/analysis_ALP/Tomas/convert_CSV_ROOT/ALP_GeneratorMC.root");

	// obtain tree
        TTree* tree	 = (TTree*)file->Get("alp_1200GeV");

	// Set output file
        TFile* outputFile = new TFile("significance_data.root", "recreate");
        TTree* outputTree = new TTree("alp_1200GeV", "data_MC");
	
	// Set branches
	double Br_luminosity;
	int Br_original_GeneratorMC_event;
	int Br_GeneratorMC_Preselected;
	int Br_GeneratorMC_selected;
	double Br_maximum_Acop;
	double Br_detecting_efficiency;
	double Br_total_expected_MC;
	double Br_total_expected_MC_less_acop;
	double Br_acoplanarity;
	double Br_MC_events;
	double Br_data_events;
	double Br_maximum_significance;
	double Br_optimized_diphotonacop;
	outputTree->Branch("luminosity", 		&Br_luminosity);
	outputTree->Branch("original_GeneratorMC_event",&Br_original_GeneratorMC_event);
	outputTree->Branch("GeneratorMC_Preselected", 	&Br_GeneratorMC_Preselected);
	outputTree->Branch("GeneratorMC_selected", 	&Br_GeneratorMC_selected);
	outputTree->Branch("maximum_Acop", 		&Br_maximum_Acop);
	outputTree->Branch("detecting_efficiency", 	&Br_detecting_efficiency);
	outputTree->Branch("total_expected_MC",		&Br_total_expected_MC);
	outputTree->Branch("total_expected_MC_less_acop", 	&Br_total_expected_MC_less_acop);
	outputTree->Branch("acoplanarity", 		&Br_acoplanarity);
	outputTree->Branch("MC_events", 		&Br_MC_events);
	outputTree->Branch("data_events", 		&Br_data_events);
	outputTree->Branch("maximum_significance", 	&Br_maximum_significance);
	outputTree->Branch("optimized_diphotonacop", 	&Br_optimized_diphotonacop);


/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*		  	 Generator level 			*/
/*			(ALP mass 1200GeV)		 	*/
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
	tree->SetBranchAddress("1200GeV_Energy_ALP", 	&Energy_ALP);
	tree->SetBranchAddress("1200GeV_Energy_Photon1", &Energy_Photon1);
	tree->SetBranchAddress("1200GeV_Energy_Photon2", &Energy_Photon2);
	tree->SetBranchAddress("1200GeV_Mass_ALP", 	&Mass_ALP);
	tree->SetBranchAddress("1200GeV_Mass_Photon1", 	&Mass_Photon1);
	tree->SetBranchAddress("1200GeV_Mass_Photon2", 	&Mass_Photon2);
	tree->SetBranchAddress("1200GeV_Theta_Photon1", 	&Theta_Photon1);
	tree->SetBranchAddress("1200GeV_Theta_Photon2", 	&Theta_Photon2);
	tree->SetBranchAddress("1200GeV_Eta_Photon1", 	&Eta_Photon1);
	tree->SetBranchAddress("1200GeV_Eta_Photon2", 	&Eta_Photon2);
	tree->SetBranchAddress("1200GeV_TransverseMomentum_Photon1", 	&TransverseMomentum_Photon1);
	tree->SetBranchAddress("1200GeV_TransverseMomentum_Photon2", 	&TransverseMomentum_Photon2);
	tree->SetBranchAddress("1200GeV_Acoplanarity", 	&DiphotonAcoplanarity);
		



	//histogram of Acoplanarity  
        //TH1D* Generator_Acop_1200GeV= new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5
        TH1D *MC_Acop_all = new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5
        TH1D *GeneratorMC_Acop = new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5


       /**********   Start main Loop of Generator level with 1200 GeV ALP mass(ALP_GeneratorMC.root)   **********/
        double maximum_Acop = 0;
        int GeneratorMC_Preselected = 0;
        int GeneratorMC_selected = 0;
        double acoplanarity = 0.002;
        Long64_t GeneratorMC_total = tree->GetEntries();
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

                MC_Acop_all->Fill(DiphotonAcoplanarity);
                GeneratorMC_Preselected++;

                //Arbitrary selction by user            
                if(!(DiphotonAcoplanarity <= acoplanarity)){
                continue;
                }


                GeneratorMC_Acop->Fill(DiphotonAcoplanarity);
        }

	GeneratorMC_selected = GeneratorMC_Acop->GetEntries();

        cout<< "####################  Generator leve  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "maximum_Acop;                   " <<  maximum_Acop << endl;
        cout<< "GeneratorMC_Preselected;        " <<  GeneratorMC_Preselected << endl;
        cout<< "GeneratorMC_selected;           " <<  GeneratorMC_selected << endl;
        cout<< ""<<endl;
        cout<< "##########################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;

	


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
	/*	Rescale events of MC		*/
	/*					*/
	/****************************************/

	GeneratorMC_Acop->Sumw2();// Sumw2 has to be done before Scale()
        double luminosity = 32;
        double cross_section = 6.0821;
        double original_GeneratorMC_event = 5000;
        double detecting_efficiency = GeneratorMC_Preselected / original_GeneratorMC_event;
        double expected_MC = luminosity * cross_section * detecting_efficiency; // expected detectable signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
        MC_Acop_all->Scale(expected_MC/GeneratorMC_Preselected);
        double bin_size = 0.0216/540;//binning size is 4e-5
        double Nbin  = acoplanarity/bin_size;//250
        double A4 = MC_Acop_all->Integral(0, Nbin);
        GeneratorMC_Acop->Scale(A4/GeneratorMC_Acop->GetEntries());

        cout<< "####################  Generator MC(1200GeV)  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "Luminosity;                     " << luminosity << '\n';
        cout<< "Cross section;                  " << cross_section << '\n';
        cout<< "Original GeneratorMC_event;     " << original_GeneratorMC_event << '\n';
        cout<< "Detecting efficiency;           " << detecting_efficiency<< '\n';
        cout<< "Expected MC events(1200GeV);     " << expected_MC << '\n';
        cout<< Form("Expected MC events between 0 and %f        ", acoplanarity) << A4 << '\n';
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

        //histogram of TGraph :: Calculate significance for each ALP mass for 1200GeV 
        //Set range of DiphotonAcop
        double end_DiphotonAcop = acoplanarity;
        const double Nplot = 50;// Nplot should be, Nplot<= 50 
        double start_DiphotonAcop = end_DiphotonAcop/Nplot;
        const double increment = start_DiphotonAcop;
        double significance;
        double maximum_significance = 0;
        double diphotonacop;
	double optimized_MC_events;
	double optimized_data_events;
        end_DiphotonAcop += increment;//according to the precision of double

        TGraph* significance_DiphotonAcop = new TGraph(Nplot);
        significance_DiphotonAcop->SetTitle(" ; DiphotonAcop; significance");
        significance_DiphotonAcop->GetXaxis()->SetLabelSize(0.03);
        significance_DiphotonAcop->GetYaxis()->SetLabelSize(0.03);
        significance_DiphotonAcop->SetMarkerStyle(20);
        significance_DiphotonAcop->SetMarkerSize(1.0);
        significance_DiphotonAcop->SetMarkerColor(1);
        //significance_DiphotonAcop->GetYaxis()->SetRangeUser(0,"2");
        significance_DiphotonAcop->SetMinimum(0);

        while(start_DiphotonAcop <= end_DiphotonAcop){
                //Set parameters for Loop
                significance = 0.;
                double MC_events = 0.;
                double data_events = 0.;

                ////  Pattern 2 ////
                MC_ibin = start_DiphotonAcop/bin_size;
                MC_events = GeneratorMC_Acop->Integral(0, MC_ibin);
		data_events = 200 * MC_ibin;//background is constant according to Invariant Mass>=1200GeV
		
		//calculation fo significance
                significance = (double)(MC_events) /sqrt(MC_events + data_events);
                if(maximum_significance < significance){
                maximum_significance = significance;
                diphotonacop = start_DiphotonAcop;
		optimized_MC_events = MC_events;
		optimized_data_events = data_events;
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

		//Fill
		Br_luminosity 			= 	luminosity;
		Br_original_GeneratorMC_event	=	5000;
	 	Br_GeneratorMC_Preselected	=	GeneratorMC_Preselected;
	 	Br_GeneratorMC_selected		=	GeneratorMC_selected;
	 	Br_maximum_Acop 		=	maximum_Acop;
		Br_detecting_efficiency		=	detecting_efficiency;
		Br_total_expected_MC		=	expected_MC;
		Br_total_expected_MC_less_acop	=	A4;
		Br_acoplanarity			=	start_DiphotonAcop;
		Br_MC_events			=	MC_events;
		Br_data_events			=	data_events;
		Br_maximum_significance		=	maximum_significance;
		Br_optimized_diphotonacop	=	diphotonacop;
	
		outputTree->Fill();
		

        }

	cout<<"/*****************************************/"<<endl;
	cout<<"/*	                              	*/"<<endl;
	cout<<"/*	Optimization of acoplanarity	*/"<<endl;
   	cout<<"/*					*/"<<endl; 
	cout<<"/*****************************************/"<<endl;
        cout<< ""<<endl;

 	cout<<" GeneratorMC_Preselected;        		"<<  GeneratorMC_Preselected << endl;
 	cout<<" GeneratorMC_selected;        			"<<  GeneratorMC_selected << endl;
	cout<<" maximum_Acop;                   		"<<  maximum_Acop << endl;
	cout<<" Detecting efficiency;           		"<<  detecting_efficiency<< '\n';
	cout<<" Expected MC events(1200GeV);     		"<<  expected_MC << '\n';
	cout<< Form(" Expected MC events between 0 and %f;       ", acoplanarity) << A4 << '\n';
        cout<<" MC_events;              			"<<  optimized_MC_events   << '\n';
        cout<<" data_events;            			"<<  optimized_data_events << '\n';
        cout<<" diphotonacop;           			"<<  diphotonacop<<endl;
	cout<<" maximum_significance;   			"<<  maximum_significance<<endl;

        cout<< ""<<endl;
        cout<< "##########################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;


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
	TCanvas *c1200 = new TCanvas("c1200", "c1200");
	significance_DiphotonAcop->Draw("AP");
    	c1200->Modified();
	c1200->SetWindowSize(830, 550);
    	//significance_DiphotonAcop[i]->SetStats(0); //SetStats object is only for TH1D
	//significan_DiphotonAcop->SetTitle("PhotonPt2:PhotonPt1");
	//significan_DiphotonAcop->SetName("signalMC");

	//gPad->Update();
	//TPaveStats *st6 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	//st6->SetName("mystats"); //it works whether it is command or not
	//st6->SetShadowColor(0);
	//gPad->Modified();
	//gPad->Update();
	c1200->Update();
     	c1200->SaveAs("./pdf/1200.pdf");



	outputTree->Write();
	outputFile->Close();


return 0;

}	
