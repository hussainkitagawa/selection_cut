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

void ALP_400(){
	
	//invoking the ATLAS style function	
	SetAtlasStyle();
	


	// obtain rootfile
	TFile *file = new TFile("/Users/kitagawa/analysis_ALP/Tomas/convert_CSV_ROOT/ALP_GeneratorMC.root");

	// obtain tree
        TTree* tree	 = (TTree*)file->Get("alp_400GeV");

	// Set output file
        //TFile* outputFile = new TFile("data_MC.root", "recreate");
        //TTree* outputTree = new TTree("data_MC", "data_MC");


/****************************************************************/
/*                                                              */
/*                                                              */
/*                                                              */
/*		  	 Generator level 			*/
/*			(ALP mass 400GeV)		 	*/
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
	tree->SetBranchAddress("400GeV_Energy_ALP", 	&Energy_ALP);
	tree->SetBranchAddress("400GeV_Energy_Photon1", &Energy_Photon1);
	tree->SetBranchAddress("400GeV_Energy_Photon2", &Energy_Photon2);
	tree->SetBranchAddress("400GeV_Mass_ALP", 	&Mass_ALP);
	tree->SetBranchAddress("400GeV_Mass_Photon1", 	&Mass_Photon1);
	tree->SetBranchAddress("400GeV_Mass_Photon2", 	&Mass_Photon2);
	tree->SetBranchAddress("400GeV_Theta_Photon1", 	&Theta_Photon1);
	tree->SetBranchAddress("400GeV_Theta_Photon2", 	&Theta_Photon2);
	tree->SetBranchAddress("400GeV_Eta_Photon1", 	&Eta_Photon1);
	tree->SetBranchAddress("400GeV_Eta_Photon2", 	&Eta_Photon2);
	tree->SetBranchAddress("400GeV_TransverseMomentum_Photon1", 	&TransverseMomentum_Photon1);
	tree->SetBranchAddress("400GeV_TransverseMomentum_Photon2", 	&TransverseMomentum_Photon2);
	tree->SetBranchAddress("400GeV_Acoplanarity", 	&DiphotonAcoplanarity);
		



	//histogram of Acoplanarity  
        //TH1D* Generator_Acop_400GeV= new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5
        TH1D *MC_Acop_all = new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5
        TH1D *GeneratorMC_Acop = new TH1D("", "", 540, 0, 0.0216);//binning size is 4e-5


       /**********   Start main Loop of Generator level with 400 GeV ALP mass(ALP_GeneratorMC.root)   **********/
        double maximum_Acop = 0;
        int GeneratorMC_Preselected = 0;
        double acoplanarity = 0.02;
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

        cout<< "####################  Generator leve  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "maximum_Acop;                   " <<  maximum_Acop << endl;
        cout<< "GeneratorMC_Preselected;        " <<  GeneratorMC_Preselected << endl;
        cout<< "GeneratorMC_pass;               " <<    GeneratorMC_Acop->GetEntries()<< endl;
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

        cout<< "####################  Generator MC(400GeV)  ####################"<<endl;
        cout<< ""<<endl;
        cout<< "Luminosity;                     " << luminosity << '\n';
        cout<< "Cross section;                  " << cross_section << '\n';
        cout<< "Original GeneratorMC_event;     " << original_GeneratorMC_event << '\n';
        cout<< "Detecting efficiency;           " <<  detecting_efficiency<< '\n';
        cout<< "Expected MC events(400GeV);     " << expected_MC << '\n';
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

        //histogram of TGraph :: Calculate significance for each ALP mass for 400GeV 
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
		data_events = 200 * MC_ibin;//background is constant according to Invariant Mass>=400GeV
		
		//calculation fo significance
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
	TCanvas *c400 = new TCanvas("c400", "c400");
	significance_DiphotonAcop->Draw("AP");
    	c400->Modified();
	c400->SetWindowSize(830, 550);
    	//significance_DiphotonAcop[i]->SetStats(0); //SetStats object is only for TH1D
	//significan_DiphotonAcop->SetTitle("PhotonPt2:PhotonPt1");
	//significan_DiphotonAcop->SetName("signalMC");

	//gPad->Update();
	//TPaveStats *st6 = (TPaveStats*)data_Pt_2D->FindObject("stats");
	//st6->SetName("mystats"); //it works whether it is command or not
	//st6->SetShadowColor(0);
	//gPad->Modified();
	//gPad->Update();
	c400->Update();
        c400->SaveAs("./pdf/400.pdf");


//	outputFile->Close();

return 0;

}	
