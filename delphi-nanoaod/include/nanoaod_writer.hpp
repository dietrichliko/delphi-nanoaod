#ifndef NANOAOD_WRITER_HPP
#define NANOAOD_WRITER_HPP

#include <filesystem>
#include <vector>

#include "skelana_analysis.hpp"
#include "skelana.hpp"

#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleWriter.hxx>
#include <Math/Vector4D.h>
#include <Math/Vector3D.h>
#include <Math/SMatrixFfwd.h>

using RNTupleWriter = ROOT::Experimental::RNTupleWriter;
using RNTupleModel = ROOT::Experimental::RNTupleModel;

namespace sk = skelana;

typedef ROOT::Math::XYZTVectorF XYZTVectorF;
typedef ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D<float>, ROOT::Math::DefaultCoordinateSystemTag > XYZVectorF;
typedef ROOT::Math::PositionVector3D< ROOT::Math::Cartesian3D<float>, ROOT::Math::DefaultCoordinateSystemTag > XYZPointF;


class NanoAODWriter : public sk::Analysis
{
private:
    typedef sk::Analysis super;

public:
    NanoAODWriter(const NanoAODWriter &) = delete;
    NanoAODWriter &operator=(const NanoAODWriter &) = delete;
    virtual ~NanoAODWriter();
    static NanoAODWriter *getInstance();
    void setOutput(const std::filesystem::path &output);
    void setMC();

protected:
    NanoAODWriter();
    virtual void user00();
    virtual int user01();
    virtual void user02();
    virtual void user99();

private:
    void defineEvent(std::unique_ptr<RNTupleModel> &model);
    void fillEvent();
    void definePart(std::unique_ptr<RNTupleModel> &model);
    void fillPart();
    void defineJet(std::unique_ptr<RNTupleModel> &model);
    void fillJet();
    void defineVtx(std::unique_ptr<RNTupleModel> &model);
    void fillVtx();
    void defineSimPart(std::unique_ptr<RNTupleModel> &model);
    void fillSimPart();
    void defineGenPart(std::unique_ptr<RNTupleModel> &model);
    void fillGenPart();
    void defineSimVtx(std::unique_ptr<RNTupleModel> &model);
    void fillSimVtx();
    void defineBeamSpot(std::unique_ptr<RNTupleModel> &model);
    void fillBeamSpot();
    void defineTrac(std::unique_ptr<RNTupleModel> &model);
    void fillTrac();
    void defineMuid(std::unique_ptr<RNTupleModel> &model);
    void fillMuid();
    void defineElid(std::unique_ptr<RNTupleModel> &model);
    void fillElid();
    void defineHadid(std::unique_ptr<RNTupleModel> &model);
    void fillHadid();
    void defineBtag(std::unique_ptr<RNTupleModel> &model);
    void fillBtag();

    std::filesystem::path output_;
    std::unique_ptr<RNTupleWriter> writer_;
    bool mc_;

    std::shared_ptr<int> Event_runNumber_;
    std::shared_ptr<int> Event_eventNumber_;
    std::shared_ptr<int> Event_fillNumber_;
    std::shared_ptr<int> Event_date_;
    std::shared_ptr<int> Event_time_;
    std::shared_ptr<float> Event_magField_;
    std::shared_ptr<float> Event_cmEnergy_;
    std::shared_ptr<int8_t> Event_shortDstVersion_;
    std::shared_ptr<int8_t> Event_hadronTag_;
    std::shared_ptr<int16_t> Event_nChaMultT4_;
    std::shared_ptr<int16_t> Event_nChaMult_;
    std::shared_ptr<int16_t> Event_nNeuMult_;
    std::shared_ptr<float> Event_totalChaEnergy_;
    std::shared_ptr<float> Event_totalEMEnergy_;
    std::shared_ptr<float> Event_totalHadEnergy_;
    std::shared_ptr<std::string> Event_DSTType_;

    std::shared_ptr<int16_t> nPart_;
    std::shared_ptr<std::vector<XYZTVectorF>> Part_vector_;
    std::shared_ptr<std::vector<int16_t>> Part_charge_;
    std::shared_ptr<std::vector<int16_t>> Part_pdgId_;
    std::shared_ptr<std::vector<int>> Part_massid_;
    std::shared_ptr<std::vector<int16_t>> Part_jetnr_;
    std::shared_ptr<std::vector<int>> Part_lock_;
    std::shared_ptr<std::vector<int16_t>> Part_simIdx_;
    std::shared_ptr<std::vector<int16_t>> Part_originVtxIdx_;
    std::shared_ptr<std::vector<int16_t>> Part_decayVtxIdx_;

    std::shared_ptr<int16_t> nJet_;
    std::shared_ptr<std::vector<XYZTVectorF>> Jet_vector_;
    std::shared_ptr<std::vector<int16_t>> Jet_charge_;

    std::shared_ptr<float> Jet_thrust_;
    std::shared_ptr<float> Jet_oblatness_;
    std::shared_ptr<std::vector<XYZVectorF>> Jet_thrustVector_;
    std::shared_ptr<float> Jet_sphericity_;
    std::shared_ptr<float> Jet_aplanarity_;
    std::shared_ptr<std::vector<XYZVectorF>> Jet_sphericityVector_;

    std::shared_ptr<int16_t> nSimPart_;
    std::shared_ptr<std::vector<XYZTVectorF>> SimPart_vector_;
    std::shared_ptr<std::vector<int16_t>> SimPart_charge_;
    std::shared_ptr<std::vector<int16_t>> SimPart_pdgId_;
    std::shared_ptr<std::vector<int16_t>> SimPart_partIdx_;
    std::shared_ptr<std::vector<int16_t>> SimPart_genIdx_;
    std::shared_ptr<std::vector<int16_t>> SimPart_originVtxIdx_;
    std::shared_ptr<std::vector<int16_t>> SimPart_decayVtxIdx_;

    std::shared_ptr<int16_t> nGenPart_;
    std ::shared_ptr<std::vector<int16_t>> GenPart_status_;
    std::shared_ptr<std::vector<int16_t>> GenPart_pdgId_;
    std::shared_ptr<std::vector<int16_t>> GenPart_parentIdx_;
    std::shared_ptr<std::vector<int16_t>> GenPart_firstChildIdx_;
    std::shared_ptr<std::vector<int16_t>> GenPart_lastChildIdx_;
    std::shared_ptr<std::vector<XYZTVectorF>> GenPart_vector_;
    std::shared_ptr<std::vector<XYZTVectorF>> GenPart_vertex_;
    std::shared_ptr<std::vector<float>> GenPart_tau_;
    std::shared_ptr<std::vector<int16_t>> GenPart_simIdx_;

    std::shared_ptr<int16_t> nVtx_;
    std::shared_ptr<std::vector<int16_t>> Vtx_firstOutIdx_;
    std::shared_ptr<std::vector<int16_t>> Vtx_firstInIdx_;
    std::shared_ptr<std::vector<int16_t>> Vtx_nOut_;
    std::shared_ptr<std::vector<int16_t>> Vtx_ndf_;
    std::shared_ptr<std::vector<int16_t>> Vtx_mcode_;
    std::shared_ptr<std::vector<XYZPointF>> Vtx_position_;
    std::shared_ptr<std::vector<float>> Vtx_chi2_;
    std::shared_ptr<std::vector<ROOT::Math::SMatrixSym3F>> Vtx_errorMatrix_;
    std::shared_ptr<std::vector<int16_t>> Vtx_errorFlag_;
    std::shared_ptr<std::vector<int16_t>> Vtx_status_;

    std::shared_ptr<int16_t> nSimVtx_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_firstOutIdx_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_firstInIdx_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_nOut_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_mcode_;
    std::shared_ptr<std::vector<XYZPointF>> SimVtx_vertex_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_errorFlag_;
    std::shared_ptr<std::vector<int16_t>> SimVtx_status_;

    std::shared_ptr<XYZVectorF> Beam_position_;
    std::shared_ptr<XYZVectorF> Beam_size_;

    std::shared_ptr<std::vector<int16_t>> Part_tracIdx_;
    std::shared_ptr<std::vector<int16_t>> Trac_originVtxIdx_;
    std::shared_ptr<std::vector<int16_t>> Trac_decayVtxIdx_;
    std::shared_ptr<std::vector<float>> Trac_impactParRPhi_;
    std::shared_ptr<std::vector<float>> Trac_impactParZ_;
    std::shared_ptr<std::vector<float>> Trac_thetaPerigee_;
    std::shared_ptr<std::vector<float>> Trac_phiPerigee_;
    std::shared_ptr<std::vector<float>> Trac_curvaturePerigee_;
    std::shared_ptr<std::vector<ROOT::Math::SMatrixSym5F>> Trac_weightMatrix_;
    std::shared_ptr<std::vector<float>> Trac_length_;
    std::shared_ptr<std::vector<int16_t>> Trac_detectors_;
    std::shared_ptr<std::vector<float>> Trac_rFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_zFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_chi2NoVD_;
    std::shared_ptr<std::vector<float>> Trac_chi2VD_;
    std::shared_ptr<std::vector<int16_t>> Trac_ndfNoVD_;
    std::shared_ptr<std::vector<int16_t>> Trac_ndfVD_;
    std::shared_ptr<std::vector<int16_t>> Trac_nHitVDRPhi_;
    std::shared_ptr<std::vector<int16_t>> Trac_nHitVDZ_;
    std::shared_ptr<std::vector<float>> Trac_resRPhiFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_errorResRPhiFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_resZFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_errorResZFirstPoint_;
    std::shared_ptr<std::vector<float>> Trac_impactParameterVertexGeomSign_;
    std::shared_ptr<std::vector<float>> Trac_impactParameterZGeomSign_;
    std::shared_ptr<std::vector<float>> Trac_impactParameterBeamSpotGeomSign_;
    // std::shared_ptr<std::vector<float>> Trac_energyError_;
    std::shared_ptr<std::vector<float>> Trac_chi2VDHits_;

    std::shared_ptr<std::vector<int16_t>> Part_muidIdx_;
    std::shared_ptr<std::vector<int>> Muid_tag_;
    std::shared_ptr<std::vector<float>> Muid_looseChi2_;
    std::shared_ptr<std::vector<int16_t>> Muid_hitPattern_;

    std::shared_ptr<std::vector<int16_t>> Part_elidIdx_;
    std::shared_ptr<std::vector<int>> Elid_tag_;
    std::shared_ptr<std::vector<int16_t>> Elid_gammaConversion_;
    std::shared_ptr<std::vector<float>> Elid_px_;
    std::shared_ptr<std::vector<float>> Elid_py_;
    std::shared_ptr<std::vector<float>> Elid_pz_;

    std::shared_ptr<std::vector<int>> Haid_sign_;
    std::shared_ptr<std::vector<int>> Haid_kaonDedx_;
    std::shared_ptr<std::vector<int>> Haid_protonDedx_;
    std::shared_ptr<std::vector<int>> Haid_kaonRich_;
    std::shared_ptr<std::vector<int>> Haid_protonRich_;
    std::shared_ptr<std::vector<int>> Haid_pionRich_;
    std::shared_ptr<std::vector<float>> Haid_kaonCombined_;
    std::shared_ptr<std::vector<float>> Haid_protonCombined_;
    std::shared_ptr<std::vector<int>>Haid_richQuality_;

    std::shared_ptr<std::vector<int8_t>> Haidn_pionTag_;
    std::shared_ptr<std::vector<int8_t>> Haidn_kaonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidn_protonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidn_heavyTag_;
    std::shared_ptr<std::vector<int8_t>> Haidn_pionTrackSelection_;
    std::shared_ptr<std::vector<int8_t>> Haidn_kaonTrackSelection_;
    std::shared_ptr<std::vector<int8_t>> Haidn_protonTrackSelection_;
    std::shared_ptr<std::vector<int8_t>> Haidn_heavyTrackSelection_;

    std::shared_ptr<std::vector<int8_t>> Haidr_pionTag_;
    std::shared_ptr<std::vector<int8_t>> Haidr_kaonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidr_protonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidr_heavyTag_;
    std::shared_ptr<std::vector<int8_t>> Haidr_electronTag_;
    std::shared_ptr<std::vector<int8_t>> Haidr_selectionFlag_;

    std::shared_ptr<std::vector<int8_t>> Haide_pionTag_;
    std::shared_ptr<std::vector<int8_t>> Haide_kaonTag_;
    std::shared_ptr<std::vector<int8_t>> Haide_protonTag_;
    std::shared_ptr<std::vector<int8_t>> Haide_heavyTag_;
    std::shared_ptr<std::vector<int8_t>> Haide_electronTag_;
    std::shared_ptr<std::vector<int8_t>> Haide_selectionFlag_;

    std::shared_ptr<std::vector<int8_t>> Haidc_pionTag_;
    std::shared_ptr<std::vector<int8_t>> Haidc_kaonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidc_protonTag_;
    std::shared_ptr<std::vector<int8_t>> Haidc_heavyTag_;
    std::shared_ptr<std::vector<int8_t>> Haidc_electronTag_;
    std::shared_ptr<std::vector<int8_t>> Haidc_selectionFlag_;

    std::shared_ptr<std::vector<float>>  Dedx_value_;
    std::shared_ptr<std::vector<float>>  Dedx_width_;
    std::shared_ptr<std::vector<int16_t>> Dedx_nrWires_; 
    std::shared_ptr<std::vector<float>> Dedx_gapWires_; 
    std::shared_ptr<std::vector<float>>  Dedx_error_;
    std::shared_ptr<std::vector<float>>  Dedx_valueVD_; 
    std::shared_ptr<std::vector<int16_t>> Dedx_nrVDHits_;

    std::shared_ptr<std::vector<float>> Rich_theg_;
    std::shared_ptr<std::vector<float>> Rich_sigg_;
    std::shared_ptr<std::vector<int16_t>> Rich_nphg_;
    std::shared_ptr<std::vector<float>> Rich_nepg_;
    std::shared_ptr<std::vector<int16_t>> Rich_flagg_;
    std::shared_ptr<std::vector<float>> Rich_thel_;
    std::shared_ptr<std::vector<float>> Rich_sigl_;
    std::shared_ptr<std::vector<int16_t>> Rich_nphl_;
    std::shared_ptr<std::vector<float>> Rich_nepl_;
    std::shared_ptr<std::vector<int16_t>> Rich_flagl_;

    std::shared_ptr<std::vector<float>> Btag_probNegIP_;
    std::shared_ptr<std::vector<float>> Btag_probPosIP_;
    std::shared_ptr<std::vector<float>> Btag_probAllIP_;
    std::shared_ptr<XYZVectorF> Btag_thrustVector_; 

};

#endif // NANOAOD_WRITER_HPP