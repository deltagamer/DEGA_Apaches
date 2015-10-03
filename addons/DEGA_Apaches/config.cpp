#include "config_extra.hpp"
#include "Crewanimations.hpp"
#define PosY0Center 0.03
#define PosYCenterHorizont 0.50
#define PosX0Center 0.52
#define SizeX10deg 1.5
#define SizeY10deg 1.2

class CfgVehicles
{
	class AllVehicles;
	class Air: AllVehicles
	{
		class NewTurret;
		class ViewPilot;
	};
	class Helicopter: Air
	{
		class Turrets
		{
			class MainTurret;
		};
		class NewTurret;
		class AnimationSources;
		class HitPoints;
	};
	class Helicopter_Base_F: Helicopter
	{
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitHRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;		
		};
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class ViewOptics;
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Apache////////////////////////////////////
///////////////////////////////////////Base/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_AH64_Base : Helicopter_Base_F
	{
		scope = 1;
		side = 1;
		scopeCurator = 0;		// 2 means available from Zeus, whereas 0 means hidden		
		accuracy=5;
		cost=10000000;
		armor=50;
		driverCanEject = 0;
		damageResistance = 0.00555;
		laserScanner = 1;
		MainRotorSpeed = -1.0;
		backRotorSpeed =  3.0;
		driverRightHandAnimName = "stick";
	    author = "Deltagamer";		
		availableForSupportTypes[] = {"CAS_Heli"};	
		picture = "\DEGA_Apaches\Data\UI\Picture_ah64d_CA.paa";
		icon = "\DEGA_Apaches\Data\UI\Icon_ah64d_CA.paa";	
		faction = "BLU_F";		
		supplyRadius = 5; // needs the memory point "doplnovani"
		maxMainRotorDive = 1; // rotor diving capability
		minMainRotorDive = 1; // rotor diving capability
		neutralBackRotorDive = 1;				
		driveOnComponent[] = {"Wheels"};
		#include "\DEGA_Apaches\Kimi\classMFD_APACHE_Kimi.hpp"
		vehicleClass = "Air";
		selectionHRotorStill = "velka vrtule staticka";
		selectionHRotorMove = "velka vrtule blur";
		selectionVRotorStill = "mala vrtule staticka";
		selectionVRotorMove = "mala vrtule blur";			
		tf_RadioType_api = "tf_anarc210";
		tf_hasLRradio_api = 1; // 1 = true, 0 = false
		tf_isolatedAmount_api = 0.2;		
		attenuationEffectType = "HeliAttenuation";	
		mapSize = 15.5;
        simulation = "HelicopterX";
		maxSpeed = 293;
		displayName = "AH64D Apache Base";
		driverAction = "AH64_Pilot_EP1";
		driverInAction = "AH64_Pilot_EP1";
		//threat[]={1, 1, 0.5};
        #include "\DEGA_Apaches\Kimi\cfgAH64_HUD.hpp"			
		weapons[]={"CMFlareLauncher", "FFARLauncher"};
	    magazines[]={"168Rnd_CMFlare_Chaff_Magazine","38Rnd_FFAR"}; // just some 38 rockets	
		memoryPointLMissile = "Rocket_1";
		memoryPointRMissile = "Rocket_2";		
		crew = "B_Helipilot_F";
		typicalCargo[]={B_Helipilot_F,B_Helipilot_F};		
		destrType="DestructWreck";
		selectionFireAnim = "zasleh";		
		enableManualFire = 1;		
		class TransportBackpacks
		{
			class _xx_B_Parachute
			{
				backpack = "B_Parachute";
				count = 2;
			};
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 6;
			};
		};		
		class UserActions
		{
			class Pimfdpip1ON
			{
				displayName= "<t color='#ffff00'>Turn On FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip12"" < 0.5 AND (player == (driver this) && (alive this)) ";
				statement="this animate [""copip12"",1];";
				priority=9;
			}; 	
			class Pimfdpip1OFF
			{
				displayName= "<t color='#ffff00'>Turn Off FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip12"" > 0.5 AND (player == (driver this) && (alive this))";
				statement="this animate [""copip12"",0];";
				priority=9;
			}; 			
		};		
		soundGetIn[]={"DEGA_Apaches\Data\sounds\close",db-10,1};
		soundGetOut[]={"DEGA_Apaches\Data\sounds\open",db-10,1, 40};
		soundEnviron[] = {"",0.031622775,1.0};
		soundDammage[]={"DEGA_Apaches\Data\sounds\alarm_loop1", db-5, 1};
		soundEngineOnInt[] = {"DEGA_Apaches\Data\sounds\AH64_start_int", db-20, 1.0};
		soundEngineOnExt[] = {"DEGA_Apaches\Data\sounds\AH64_start_ext", db-5, 1.0, 800};
		soundEngineOffInt[] =  {"DEGA_Apaches\Data\sounds\AH64_stop_int", db-20, 1.0};
		soundEngineOffExt[] =  {"DEGA_Apaches\Data\sounds\AH64_stop_ext", db-5, 1.0, 800};
		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1",0.1,1};
		soundIncommingMissile[] = {"\A3\Sounds_F\weapons\Rockets\locked_3",0.1,1.5};		
		class Sounds
		/* EXTERNAL SOUNDS AH64 */
		{
			class Engine
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_engine_1", db10, 1.0, 1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_rotor_ext2", db10, 1.0, 1200};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14, 2.0, 0.9};
			};
			class RotorHighOut
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_rotor_high_ext2", db5, 1.0, 1300};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))" ;
				cone[] = {1.8,3.14, 2.0, 0.9};
			};

		/* INTERNAL SOUNDS AH64 */
  			class EngineIn
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_engine_int", db5, 1.0};
				frequency = "rotorSpeed";
			 	volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_rotor_int2", db5, 1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"DEGA_Apaches\Data\sounds\AH64_rotor_high_int2", db5, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)" ;
			};
		};
		class Library {libTextDesc = $STR_BAF_CFGVEHICLES_BAF_APACHE_AH1_D_LIBRARY0;}; 		
		class RenderTargets /// class for all Picture-in-Picture
		{
			class camera
			{
				renderTarget = "rendertarget3";
				class CameraView1
				{
					pointPosition		= "gunnerview"; 	/// memory point of PiP origin
					pointDirection		= "gunnerview1"; 	/// memory point of PiP direction
					renderQuality 		= 4;			/// what quality should the PiP be
					renderVisionMode 	= 2;			/// zero means standard vision
					fov 				= 0.466;			/// what is the angle of the PiP field of view
				}; 	
			};
		};			
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust1";
				direction = "exhaust1_dir";
				effect = "ExhaustsEffectHeliCom";
			};
			class Exhaust2
			{
				position = "exhaust2";
				direction = "exhaust2_dir";
				effect = "ExhaustsEffectHeliCom";
			};
		};
		class MarkerLights 
		{
			class WhiteStill 
			{
				name = "bily pozicni";
				color[] = {1.0, 1.0, 1.0};
				ambient[] = {0.1, 0.1, 0.1};
				blinking = 1;
				intensity = 75;
				blinkingPattern[] = {0.1, 0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
			class RedStill 
			{
				name = "cerveny pozicni";
				color[] = {0.8, 0.0, 0.0};
				ambient[] = {0.08, 0.0, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};
			class GreenStill 
			{
				name = "zeleny pozicni";
				color[] = {0.0, 0.8, 0.0};
				ambient[] = {0.0, 0.08, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};
			class RedBlinking 
			{
				name = "bily pozicni blik";
				color[] = {0.9, 0.15, 0.1};
				ambient[] = {0.09, 0.015, 0.01};
				intensity = 75;
				blinking = 1;
				blinkingPattern[] = {0.1, 0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
			class WhiteBlinking 
			{
				name = "cerveny pozicni blik";
				color[] = {0.9, 0.15, 0.1};
				intensity = 75;
				ambient[] = {0.09, 0.015, 0.01};
				blinking = 1;
				blinkingPattern[] = {0.2, 1.3};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.08;
			};
		};
		class Reflectors
		{
			class Right
			{
				color[] = {7000,7500,10000};	/// defines red, green, blue and alpha components of the light
				ambient[] = {70,75,100};		/// the same definition format for colouring the environment around
				intensity = 50;					/// how much does the light shine (in some strange units, just tweak until it is satisfying), rough approximation is intensity = (brightness * 50) ^ 2
				size = 1;						/// defines the visible size of light, has not much of an effect now
				innerAngle = 20;				/// angle from light direction vector where the light is at full strength
				outerAngle = 135;				/// angle from light direction vector where the light is completely faded out
				coneFadeCoef = 10;				/// coefficient of fading the light between inner and outer cone angles
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				useFlare = true;				/// boolean switch if the light produces flare or not
				flareSize = 15;					/// how big is the flare, using the same metrics as intensity
				flareMaxDistance = 300;			/// maximum distance where the flare is drawn
				dayLight = false;				/// boolean switch if the light is used during day or not
				class Attenuation
				{
					start = 0;					/// offset of start of the attenuation
					constant = 0;				/// constant attenuation of the light in any distance from source
					linear = 1;					/// coefficient for linear attenuation
					quadratic = 1;				/// coefficient for attenuation with square of distance from source
					hardLimitStart = 100;		/// distance from source where the light intensity decreases for drawing
					hardLimitEnd = 200;			/// distance from source where the light is not displayed (shorter distances increase performance)
				};
			};			
		};
		class AnimationSources
		{
			class HitGlass1
			{
				source = "Hit";
				hitpoint = "HitGlass1";
				raw = 1;
			};
			class HitGlass2: HitGlass1
			{
				hitpoint = "HitGlass2";
			};
			class HitGlass3: HitGlass1
			{
				hitpoint = "HitGlass3";
			};
			class HitGlass4: HitGlass1
			{
				hitpoint = "HitGlass4";
			};
			class HitGlass5: HitGlass1
			{
				hitpoint = "HitGlass4";
			};
			class Gatling
			{
				source = "revolving";
				weapon = "M230";
			};
			class Hide
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
			class Hide_MFD_Pilot
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};	
			class Hide_Radar
			{
				source="user";
				animPeriod=0;
				initPhase=1;
			};					
			/*class Muzzle_flash
			{
				source = "ammorandom";
				weapon = "M230";
			};*/
		};
		class HitPoints: HitPoints
		{
			/*class HitHull
			{
				name = "hull";
				visual = "zbytek";
			};
			class HitHRotor
			{
				armor = 0.3;
			};*/
			/*class HitGlass1
			{
				armor = 3;
			};
			class HitGlass2
			{
				armor = 3;
			};
			class HitGlass3
			{
				armor = 1;
			};
			class HitGlass4
			{
				armor = 1;
			};*/
		};
		//class HitPoints : HitPoints
		//{
			//class HitGlass1 {armor=0.5;};
			//class HitGlass2 {armor=0.5;};
			//class HitGlass3 {armor=0.5;};
			//class HitGlass4 {armor=0.5;};
			//class HitGlass5 {armor=0.5;};
		//};
		dammageHalf[]=
		{
			"\DEGA_Apaches\Data\AH64D_mfd_normal_co.paa", "\DEGA_Apaches\Data\AH64D_mfd_malfc_co.paa"
		};
		dammageFull[]=
		{
			"\DEGA_Apaches\Data\AH64D_mfd_normal_co.paa", "\DEGA_Apaches\Data\AH64D_mfd_malfc_co.paa"
		};
		class Damage
		{
			tex[]={};
			mat[]={
				"DEGA_Apaches\Data\AH64D_body.rvmat",
				"DEGA_Apaches\Data\AH64D_body_damage.rvmat",
				"DEGA_Apaches\Data\AH64D_body_destruct.rvmat",

				"DEGA_Apaches\Data\AH64D_details.rvmat",
				"DEGA_Apaches\Data\AH64D_details_damage.rvmat",
				"DEGA_Apaches\Data\AH64D_details_destruct.rvmat",

				"DEGA_Apaches\Data\AH64D_inter.rvmat",
				"DEGA_Apaches\Data\AH64D_inter_damage.rvmat",
				"DEGA_Apaches\Data\AH64D_inter_destruct.rvmat",

				"DEGA_Apaches\Data\AH64D_glass.rvmat",
				"DEGA_Apaches\Data\AH64D_glass_damage.rvmat",
				"DEGA_Apaches\Data\AH64D_glass_damage.rvmat",

				"DEGA_Apaches\Data\AH64D_glass_in.rvmat",
				"DEGA_Apaches\Data\AH64D_glass_in_damage.rvmat",
				"DEGA_Apaches\Data\AH64D_glass_in_damage.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"DEGA_Apaches\Data\default_destruct.rvmat"
			};
		};
		class CargoTurret;		
		class Turrets:Turrets
		{					
			class MainTurret : MainTurret
			{
				gunnerAction = AH64_Gunner_EP1;
				gunnerInAction = AH64_Gunner_EP1;
				minElev        =    -60; maxElev        =    +30; initElev       =    0;
				minTurn        =    -120; maxTurn       =    +120; initTurn      =    0;
				weapons[]={"M230","HellfireLauncherL", "HellfireLauncherN", "Laserdesignator_mounted"};
				magazines[]={"1200Rnd_30x113mm_M789_HEDP", "4Rnd_Hellfire_L","4Rnd_Hellfire_N", "Laserbatteries"}; // just some 38 rockets
				enableManualFire = 1;
				radarType = 4;
				isCoPilot = 1;
				primarygunner=1;
                showHMD=1;
				memoryPointsGetInGunner= "pos_gunner";
				memoryPointsGetInGunnerDir= "pos_gunner_dir";
				gunnerGetInAction = GetInHigh;
				gunnerGetOutAction = GetOutHigh;
				memoryPointGun = "machinegun";
				turretInfoType = "RscOptics_UAV_gunner";
				discreteDistance[] = {300,400,500,600,700,800,900,1000,1100,1200};
				discreteDistanceInitIndex = 2;
				gunnerOpticsModel = "";
                class OpticsIn 
                {
	                class WideNGS
	                {
		                opticsDisplayName = "W";
		                initAngleX = 0;
		                minAngleX = -35;
		                maxAngleX = 10;
		                initAngleY = 0;
		                minAngleY = -100;
		                maxAngleY = 100;
		                initFov = 0.466;
	                	minFov = 0.466;
		                maxFov = 0.466;
		                visionMode[] = {"Normal","NVG", "Ti"};
		                thermalMode[] = {0, 1};
		                gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
		                directionStabilized=0;
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
	                };
	                class Wide 
	                {
		                opticsDisplayName = "W";
		                initAngleX = 0;
		                minAngleX = -35;
		                maxAngleX = 10;
		                initAngleY = 0;
		                minAngleY = -100;
		                maxAngleY = 100;
		                initFov = 0.466;
		                minFov = 0.466;
		                maxFov = 0.466;
		                visionMode[] = {"Normal","NVG", "Ti"};
		                thermalMode[] = {0, 1};
		                gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		                directionStabilized=1;
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
		                gunnerOpticsEffect[]=
		                {
			                "TankCommanderOptics1"
		                };
	                };
	                class WideL: Wide 
	                {
		                opticsDisplayName = "WL";
		                initFov = 0.2;
		                minFov = 0.2;
		                maxFov = 0.2;
		                //gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
		                gunnerOpticsColor[]= {0,0,0,1};
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
	                };
	                class Medium : Wide 
	                {
	 	                opticsDisplayName = "M";
		                initFov = 0.1;
		                minFov = 0.1;
		                maxFov = 0.1;
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                gunnerOpticsColor[]= {0,0,0,1};
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
	                };
	                class Narrow : Wide 
	                {
		                opticsDisplayName = "N";
		                gunnerOpticsColor[]= {0,0,0,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                initFov = 0.02;
		                minFov = 0.02;
		                maxFov = 0.02;
	                };
	                class Narrower : Wide 
	                {
		                opticsDisplayName = "N";
		                gunnerOpticsColor[]= {0,0,0,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                initFov = 0.01;
		                minFov = 0.01;
		                maxFov = 0.01;
	                };
                };
				class OpticsOut
				{
					class Monocular // 1x-3.5x
					{
						initAngleX=0; minAngleX=-30; maxAngleX=+30;
						initAngleY=0; minAngleY=-100; maxAngleY=+100;
						initFov=1.1; minFov=0.133; maxFov=1.1;
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		    class CargoTurret_01: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_bench_1";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo right";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir right";	/// direction of get in action
				gunnerName 					= "Passenger (Right Jumpseat)";	/// name of the position in the Action menu
				proxyIndex 					= 1;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -50;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 63;					/// what is the left-most possible turn of the turret
				minTurn 					= -60;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 0;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1;
				LODTurnedOut = 1;				
			};
			class CargoTurret_02: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_bench_1";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo left";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir left";	/// direction of get in action
				gunnerName 					= "Passenger (Left Jumpseat)";	/// name of the position in the Action menu
				proxyIndex 					= 2;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -50;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 60;					/// what is the left-most possible turn of the turret
				minTurn 					= -63;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 0;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1;
				LODTurnedOut = 1;				
			};		
		};		
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AH1 BAF Apache Block I////////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Apache_AH1_Block_I_BAF : DEGA_AH64_Base
	{
		scope = 2;
		side = 1;
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden		
		model="\DEGA_Apaches\AH_BAF.p3d";
	    author = "Deltagamer"; 
		displayname = "AH1 BAF Apache Block I";	
		hiddenSelections[] ={"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"dega_apaches\data\ah1_baf_body_co.paa","dega_apaches\data\ah64d_details_co.paa"};	
		class AnimationSources : AnimationSources {};		
		class Turrets:Turrets
		{		
			class MainTurret : MainTurret {};		
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
        };			
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AH64D USA Apache Block I//////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Apache_AH64D_Block_I_USA : DEGA_AH64_Base
	{
		scope = 2;
		side = 1;
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden		
		model="\DEGA_Apaches\Ah64D.p3d";
	    author = "Deltagamer"; 
		displayname = "AH64D USA Apache Block I";	
		hiddenSelections[] ={"Camo1","Camo2"/*, "Camo3"*/};
		hiddenSelectionsTextures[] = {"DEGA_Apaches\Skins\ah64d_body_co.paa","DEGA_Apaches\Skins\ah64d_details_co.paa"/*,"dega_apaches\data\ah64d_alfa_ca.paa"*/};	
		class AnimationSources : AnimationSources {};		
		class Turrets:Turrets
		{		
			class MainTurret : MainTurret {};		
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
        };			
	};	
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AH1 BAF Apache Block II///////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Apache_AH1_Block_II_BAF : DEGA_AH64_Base
	{
		scope = 2;
		side = 1;
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden		
		model="\DEGA_Apaches\AH_BAF.p3d";
	    author = "Deltagamer"; 
		displayname = "AH1 BAF Apache Block II";	
		hiddenSelections[] ={"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"dega_apaches\data\ah1_baf_body_co.paa","dega_apaches\data\ah64d_details_co.paa"};	
		class AnimationSources : AnimationSources 
		{
			class Hide_Radar
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};				
		};		
		class Turrets:Turrets
		{		
			class MainTurret : MainTurret {};		
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
        };			
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AH64D USA Apache Block II/////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Apache_AH64D_Block_II_USA : DEGA_AH64_Base
	{
		scope = 2;
		side = 1;
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden		
		model="\DEGA_Apaches\Ah64D.p3d";
	    author = "Deltagamer"; 
		displayname = "AH64D USA Apache Block II";	
		hiddenSelections[] ={"Camo1","Camo2"/*, "Camo3"*/};
		hiddenSelectionsTextures[] = {"DEGA_Apaches\Skins\ah64d_body_co.paa","DEGA_Apaches\Skins\ah64d_details_co.paa"/*,"dega_apaches\data\ah64d_alfa_ca.paa"*/};	
		class AnimationSources : AnimationSources 
		{
			class Hide_Radar
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};				
		};		
		class Turrets:Turrets
		{		
			class MainTurret : MainTurret {};		
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
        };			
	};	
};