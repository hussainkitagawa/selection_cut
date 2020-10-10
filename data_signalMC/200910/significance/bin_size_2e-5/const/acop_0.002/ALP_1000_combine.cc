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

void ALP_1000_combine(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();
	


	// obtain rootfile
	TFile *file = new TFile("/Users/kitagawa/analysis_ALP/Tomas/convert_CSV_ROOT/ALP_GeneratorMC.root");
	TFile *file1 = new TFile("/Users/kitagawa/analysis_ALP/signalMC/diphoton.root"); //default is "read" option

	// obtain tree
        TTree* tree	 = (TTree*)file->Get("alp_1000GeV");
	TTree* diphoton = (TTree*)file1->Get("diphoton");


/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*                           SignalMC                           */
/*                      (ALP mass 1000 GeV)                     */
/*                                                              */
/*                                                              */
/****************************************************************/

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
diphoton->SetBranchAddress("PhotonPt1",                 &MC_PhotonPt1);
        diphoton->SetBranchAddress("PhotonEta1",                &MC_PhotonEta1);
        diphoton->SetBranchAddress("PhotonPhi1",                &MC_PhotonPhi1);
        diphoton->SetBranchAddress("PhotonE1",                  &MC_PhotonE1);
        diphoton->SetBranchAddress("PhotonPt2",                 &MC_PhotonPt2);
        diphoton->SetBranchAddress("PhotonEta2",                &MC_PhotonEta2);
        diphoton->SetBranchAddress("PhotonPhi2",                &MC_PhotonPhi2);
        diphoton->SetBranchAddress("PhotonE2",                  &MC_PhotonE2);
        diphoton->SetBranchAddress("DiphotonPt",                &MC_DiphotonPt);
        diphoton->SetBranchAddress("DiphotonEta",               &MC_DiphotonEta);
        diphoton->SetBranchAddress("DiphotonPhi",               &MC_DiphotonPhi);
        diphoton->SetBranchAddress("DiphotonE",                 &MC_DiphotonE);
        diphoton->SetBranchAddress("DiphotonM",                 &MC_DiphotonM);
        diphoton->SetBranchAddress("DiphotonAcop",              &MC_DiphotonAcop);
        diphoton->SetBranchAddress("DiphotonY",                 &MC_DiphotonY);
        diphoton->SetBranchAddress("DiphotonXiA",               &MC_DiphotonXiA);
        diphoton->SetBranchAddress("DiphotonXiC",               &MC_DiphotonXiC);
        diphoton->SetBranchAddress("TruthPhotonPt1",            &MC_TruthPhotonPt1);
        diphoton->SetBranchAddress("TruthPhotonEta1",           &MC_TruthPhotonEta1);
        diphoton->SetBranchAddress("TruthPhotonPhi1",           &MC_TruthPhotonPhi1);
        diphoton->SetBranchAddress("TruthPhotonE1",             &MC_TruthPhotonE1);
        diphoton->SetBranchAddress("TruthPhotonPt2",            &MC_TruthPhotonPt2);
        diphoton->SetBranchAddress("TruthPhotonEta2",           &MC_TruthPhotonEta2);
        diphoton->SetBranchAddress("TruthPhotonPhi2",           &MC_TruthPhotonPhi2);
        diphoton->SetBranchAddress("TruthPhotonE2",             &MC_TruthPhotonE2);
        diphoton->SetBranchAddress("TruthDiphotonPt",           &MC_TruthDiphotonPt);
        diphoton->SetBranchAddress("TruthDiphotonEta",          &MC_TruthDiphotonEta);
        diphoton->SetBranchAddress("TruthDiphotonPhi",          &MC_TruthDiphotonPhi);
        diphoton->SetBranchAddress("TruthDiphotonE",            &MC_TruthDiphotonE);
        diphoton->SetBranchAddress("TruthDiphotonM",            &MC_TruthDiphotonM);
        diphoton->SetBranchAddress("TruthDiphotonAcop",         &MC_TruthDiphotonAcop);
        diphoton->SetBranchAddress("TruthDiphotonY",            &MC_TruthDiphotonY);
        diphoton->SetBranchAddress("TruthDiphotonXiA",          &MC_TruthDiphotonXiA);
        diphoton->SetBranchAddress("TruthDiphotonXiC",          &MC_TruthDiphotonXiC);
        diphoton->SetBranchAddress("PhotonDeltaR1",             &MC_PhotonDeltaR1);
        diphoton->SetBranchAddress("PhotonDeltaR2",             &MC_PhotonDeltaR2);


/*    histogram of Acoplanarity    */
        TH1D *signalMC_Acop = new TH1D("", "", 1080, 0, 0.0216); //binning size is 2e-5
        TH1D *signalMC_Acop_all = new TH1D("", "", 1080, 0, 0.0216);//binning size is 2e-5


        /**********   Start main Loop of signalMC (diphoton.root)   **********/
        int signalMC_total = diphoton->GetEntries();  // total number of events
        int signalMC_selected = 0;
        double signal_maximum_Acop = 0;
        double acoplanarity = 0.002;
        for (int event = 0; event<signalMC_total; event++) {
                diphoton->GetEntry(event);

                if (signal_maximum_Acop <  MC_DiphotonAcop){

                signal_maximum_Acop = MC_DiphotonAcop;
                }

                signalMC_Acop_all->Fill(MC_DiphotonAcop);

                //Arbitrary selction by user    
                if (!(MC_DiphotonAcop <= acoplanarity)) {
                continue;
                }

                signalMC_Acop->Fill(MC_DiphotonAcop);

        }

        signalMC_selected = signalMC_Acop->GetEntries();
        cout<< "####################  Generator leve  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "maximum_Acop;                   " <<  signal_maximum_Acop << endl;
        cout<< "MC_pass;               " <<    signalMC_Acop->GetEntries()<< endl;
        cout<< ""<<endl;
        cout<< "##########################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;
/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*              significance: background is constant            */
/*                                                              */
/*                                                              */
/*                                                              */
/****************************************************************/



        /****************************************/
        /*                                      */
        /*      Rescale events of sinalMC       */
        /*                                      */
        /****************************************/

        signalMC_Acop->Sumw2();// Sumw2 has to be done before Scale()
        double luminosity = 32;
        double cross_section = 6.0821;
        double signal_detecting_efficiency = (signalMC_Acop_all->GetEntries())/10000;
        double signal_expected_MC = luminosity * cross_section * signal_detecting_efficiency; // expected detectable signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
        signalMC_Acop_all->Scale(signal_expected_MC/signalMC_Acop_all->GetEntries());
        double bin_size = 0.0216/1080;//binning size is 2e-5
        double Nbin  = acoplanarity/bin_size;
        double signal_A4 = signalMC_Acop_all->Integral(0, Nbin);
        signalMC_Acop->Scale(signal_A4/signalMC_Acop->GetEntries());


        cout<< "####################  data  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "Luminosity;                     " << luminosity << '\n';
        cout<< "Cross section;                  " << cross_section << '\n';
        cout<< "Detecting efficiency;           " <<  signal_detecting_efficiency<< '\n';
        cout<< "Expected signal MC events(1000GeV);    " << signal_expected_MC << '\n';
        cout<< Form("Expected MC events between 0 and %f        ", acoplanarity) << signal_A4 << '\n';
cout<< ""<<endl;
        cout<< "################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;


        /****************************************/
        /*                                      */
        /*      Calculation of significance     */
        /*                                      */
        /****************************************/
        //Set parameters for Loop
        int Tgraph_i= 0;
        double MC_ibin = 0;

        //Set range of DiphotonAcop
        double end_DiphotonAcop = acoplanarity;
        double Nplot = 100;// Nplot should be, Nplot<= 100
        double start_DiphotonAcop = end_DiphotonAcop/Nplot;
        const double increment = start_DiphotonAcop;
        double significance;
        double maximum_significance = 0;
        double diphotonacop;
        double optimized_MC_events;
        double optimized_data_events;
        end_DiphotonAcop += increment;//according to the precision of double    


        //histogram of TGraph
        TGraph *signal_significance_DiphotonAcop = new TGraph(Nplot);
        signal_significance_DiphotonAcop->SetTitle(" ; Diphoton acoplanarity; Significance");
        signal_significance_DiphotonAcop->GetXaxis()->SetLabelSize(0.03);
        signal_significance_DiphotonAcop->GetYaxis()->SetLabelSize(0.03);
        signal_significance_DiphotonAcop->SetMarkerStyle(22);
        signal_significance_DiphotonAcop->SetMarkerSize(0.7);
        signal_significance_DiphotonAcop->SetMarkerColor(2);
	signal_significance_DiphotonAcop->GetYaxis()->SetRangeUser(0,2);
        signal_significance_DiphotonAcop->SetMinimum(0);

        while (start_DiphotonAcop <= end_DiphotonAcop) {
                //Set parameters for Loop
                significance = 0;
                double MC_events = 0;
                double data_events = 0;

                ////  Pattern 2 ////
                MC_ibin = start_DiphotonAcop/bin_size;
                MC_events = signalMC_Acop->Integral(0, MC_ibin);
                data_events = 90* MC_ibin;


                //calculation fo significance
                significance = (double)(MC_events) /sqrt(MC_events + data_events);
                if(maximum_significance < significance){
                maximum_significance = significance;
                diphotonacop = start_DiphotonAcop;
                optimized_MC_events = MC_events;
                optimized_data_events = data_events;
                }

                //Fill to Tgraph 
                signal_significance_DiphotonAcop->SetPoint(Tgraph_i, start_DiphotonAcop, significance);
/*
                cout<<" significance;           "<< significance<<'\n';
                cout<<" MC_events;              "<< MC_events   << '\n';
                cout<<" data_events;            "<< data_events << '\n';
                cout<<" start_DiphotonAcop;     "<< setprecision(10) << start_DiphotonAcop <<'\n';
                cout<<" MC_ibin;                "<< MC_ibin <<'\n';
                cout<<""<<endl;
                cout<<""<<endl;
*/

                start_DiphotonAcop += increment;
                ++Tgraph_i;

}


        cout<<"/*****************************************/"<<endl;
        cout<<"/*                                       */"<<endl;
        cout<<"/*       Optimization of acoplanarity    */"<<endl;
        cout<<"/*                                       */"<<endl;
        cout<<"/*****************************************/"<<endl;
        cout<< ""<<endl;

        cout<<" MC_Preselected;                                 "<<  signalMC_Acop_all->GetEntries() << endl;
        cout<<" MC_selected;                                    "<<  signalMC_selected << endl;
        cout<<" maximum_Acop;                                   "<<  signal_maximum_Acop << endl;
        cout<<" Detecting efficiency;                           "<<  signal_detecting_efficiency<< '\n';
        cout<<" Expected MC events(1000GeV);                    "<<  signal_expected_MC << '\n';
        cout<< Form(" Expected MC events between 0 and %f;       ", acoplanarity) << signal_A4 << '\n';
        cout<<" MC_events;                                      "<<  optimized_MC_events   << '\n';
        cout<<" data_events;                                    "<<  optimized_data_events << '\n';
        cout<<" diphotonacop;                                   "<<  diphotonacop<<endl;
        cout<<" maximum_significance;                           "<<  maximum_significance<<endl;

        cout<< ""<<endl;
        cout<< "##########################################################"<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;
        cout<< ""<<endl;















	
	
/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*		  	 Generator level 			*/
/*			(ALP mass 1000GeV)		 	*/
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
	tree->SetBranchAddress("1000GeV_Energy_ALP", 	&Energy_ALP);
	tree->SetBranchAddress("1000GeV_Energy_Photon1", &Energy_Photon1);
	tree->SetBranchAddress("1000GeV_Energy_Photon2", &Energy_Photon2);
	tree->SetBranchAddress("1000GeV_Mass_ALP", 	&Mass_ALP);
	tree->SetBranchAddress("1000GeV_Mass_Photon1", 	&Mass_Photon1);
	tree->SetBranchAddress("1000GeV_Mass_Photon2", 	&Mass_Photon2);
	tree->SetBranchAddress("1000GeV_Theta_Photon1", 	&Theta_Photon1);
	tree->SetBranchAddress("1000GeV_Theta_Photon2", 	&Theta_Photon2);
	tree->SetBranchAddress("1000GeV_Eta_Photon1", 	&Eta_Photon1);
	tree->SetBranchAddress("1000GeV_Eta_Photon2", 	&Eta_Photon2);
	tree->SetBranchAddress("1000GeV_TransverseMomentum_Photon1", 	&TransverseMomentum_Photon1);
	tree->SetBranchAddress("1000GeV_TransverseMomentum_Photon2", 	&TransverseMomentum_Photon2);
	tree->SetBranchAddress("1000GeV_Acoplanarity", 	&DiphotonAcoplanarity);
		



	//histogram of Acoplanarity  
        TH1D *MC_Acop_all = new TH1D("", "", 1080, 0, 0.0216);//binning size is 2e-5
        TH1D *GeneratorMC_Acop = new TH1D("", "", 1080, 0, 0.0216);//binning size is 2e-5


       /**********   Start main Loop of Generator level with 1000 GeV ALP mass(ALP_GeneratorMC.root)   **********/
        double maximum_Acop = 0;
        int GeneratorMC_Preselected = 0;
        int GeneratorMC_selected = 0;
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
        double original_GeneratorMC_event = 5000;
        double detecting_efficiency = GeneratorMC_Preselected / original_GeneratorMC_event;
        double expected_MC = luminosity * cross_section * detecting_efficiency; // expected detectable signal events of ALP in a data (reference; ANA-EXOT-2019-28-INT1)
        MC_Acop_all->Scale(expected_MC/GeneratorMC_Preselected);
        double A4 = MC_Acop_all->Integral(0, Nbin);
        GeneratorMC_Acop->Scale(A4/GeneratorMC_Acop->GetEntries());

        cout<< "####################  Generator MC(1000GeV)  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "Luminosity;                     " << luminosity << '\n';
        cout<< "Cross section;                  " << cross_section << '\n';
        cout<< "Original GeneratorMC_event;     " << original_GeneratorMC_event << '\n';
        cout<< "Detecting efficiency;           " << detecting_efficiency<< '\n';
        cout<< "Expected MC events(1000GeV);     " << expected_MC << '\n';
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
        Tgraph_i = 0;
        MC_ibin = 0;

        //Set range of DiphotonAcop
        end_DiphotonAcop = acoplanarity;
        Nplot = 100;// Nplot should be, Nplot<= 100 
        start_DiphotonAcop = end_DiphotonAcop/Nplot;
        significance = 0;
        maximum_significance = 0;
        diphotonacop = 0;
	optimized_MC_events = 0;
	optimized_data_events = 0;
        end_DiphotonAcop += increment;//according to the precision of double

        TGraph* significance_DiphotonAcop = new TGraph(Nplot);
        significance_DiphotonAcop->SetTitle(" ; Diphoton acoplanarity [#times 10^{-3}]; Significance");
        significance_DiphotonAcop->GetXaxis()->SetLabelSize(0.03);
        significance_DiphotonAcop->GetYaxis()->SetLabelSize(0.03);
        significance_DiphotonAcop->SetMarkerStyle(20);
        significance_DiphotonAcop->SetMarkerSize(0.7);
        significance_DiphotonAcop->SetMarkerColor(1);
        significance_DiphotonAcop->GetYaxis()->SetRangeUser(0, 0.2);
        significance_DiphotonAcop->SetMinimum(0);

        while(start_DiphotonAcop <= end_DiphotonAcop){
                //Set parameters for Loop
                significance = 0.;
                double MC_events = 0.;
                double data_events = 0.;

                ////  Pattern 2 ////
                MC_ibin = start_DiphotonAcop/bin_size;
                MC_events = GeneratorMC_Acop->Integral(0, MC_ibin);
		data_events = 90 * MC_ibin;//background is constant according to Invariant Mass>=1000GeV
		
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
/*

                cout<<" significance;           "<< significance<<'\n';
                cout<<" MC_events;              "<< MC_events   << '\n';
                cout<<" data_events;            "<< data_events << '\n';
                cout<<" start_DiphotonAcop;     "<< setprecision(10) << start_DiphotonAcop <<'\n';
                cout<<" MC_ibin;                "<< MC_ibin <<'\n';
                cout<<""<<endl;
                cout<<""<<endl;
*/

                start_DiphotonAcop += increment;
                ++Tgraph_i;


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
	cout<<" Expected MC events(1000GeV);     		"<<  expected_MC << '\n';
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
	TCanvas *c1000 = new TCanvas("c1000", "c1000");
	significance_DiphotonAcop->Draw("AP");
	signal_significance_DiphotonAcop->Draw("P");
    	c1000->Modified();
	c1000->SetWindowSize(830, 550);

	TLegend *legend = new TLegend();
        //legend->SetNColumns(3);
        legend->AddEntry(significance_DiphotonAcop, "Generator level", "p");
       	legend->AddEntry(signal_significance_DiphotonAcop, "Signal MC", "p");
        legend->SetFillColor(0);
        legend->SetBorderSize(0);
        legend->SetShadowColor(0);
	gStyle->SetStripDecimals(false);
    	((TGaxis*)significance_DiphotonAcop->GetYaxis())->SetMaxDigits(2);
        legend->Draw();
        gPad->RedrawAxis();
        gPad->Update();
        //TPaveStats *st1 = (TPaveStats*)MC_Acop_masses->FindObject("stats");
        //st1->SetName("mystats"); //it works whether it is command or not
        //st1->SetShadowColor(0);
        //gPad->Modified();
        //gPad->Update();

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





return 0;

}	
