class CfgPatches
{
	class DEGA_Apaches
	{
		units[] = 
		{
		    "DEGA_Apache_AH1_Block_I_BAF",
			"DEGA_Apache_AH64D_Block_I_USA",
			"DEGA_Apache_AH1_Block_II_BAF",
			"DEGA_Apache_AH64D_Block_II_USA"
		};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"A3_Air_F", "A3_Weapons_F"};
	};
};

class CfgNonAIVehicles
{
	class ProxyDriver;
	class ProxyWeapon;
	class ProxyAGM114Hellfire: ProxyWeapon
	{
		model = "\DEGA_Apaches\data\Weapons\AGM114\AGM114Hellfire";
		simulation = "maverickweapon";
	};
};

class RscControlsGroup;
class RscText;
class RangeText: RscText {};
class RscPicture;
class RscOpticsText;
class RscIGProgress;
class RscOpticsValue;
class VScrollbar;
class HScrollbar;
class RscLadderPicture;
class RscInGameUI
{
	class RscUnitInfo;
	class Rsc_LilB_Kimi_Base: RscUnitInfo
	{
		controls[]=
		{
			"WeaponInfoControlsGroupRight",
			"CA_BackgroundVehicle",
			"CA_BackgroundVehicleTitle",
			"CA_BackgroundVehicleTitleDark",
			"CA_BackgroundFuel",
			"CA_Vehicle",
			"CA_VehicleRole",
			"CA_HitZones",
			"CA_SpeedBackground",
			"CA_SpeedUnits",
			"CA_Speed",
			"CA_ValueFuel",
			"CA_AltBackground",
			"CA_AltUnits",
			"CA_Alt",
			"CA_TextFlaresMode",
			"CA_TextFlares",
			//"CA_Stabilize",
			"CA_Radar"
		};
		class CA_HMDs_Kimi_Autohover: RscPicture
		{
			shadow = 1;
			idc = 1204;
			text = "\DEGA_Apaches\data\autohover_ca.paa";
			x = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "0.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	class Rsc_LilB_Kimi_UI_Turret: Rsc_LilB_Kimi_Base
	{
		idd=300;
		controls[]=
		{
			//"WeaponInfoControlsGroupRight",
			"CA_Zeroing",
			/*"CA_Speed",
			"CA_Alt",*/
			"CA_IGUI_elements_group",
			//"CA_Compass",
			"CA_HMDs_Kimi_Autohover"
			//"CA_Radar"
		};
		class VScrollbar;
		class HScrollbar;
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc=170;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w="53.5 * 		(0.01875 * SafezoneH)";
			h="40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc=151;
					style=2;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					//text="2456";
					x="24.78 * 		(0.01875 * SafezoneH)";
					y="30.88 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Speed: RangeText
				{
					//idc=530;
					idc = 188; // metric=188, imp=606?
					style=2;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text = "120";
					x="14.78 * 		(0.01875 * SafezoneH)";
					y="30.88 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Alt: RangeText
				{
					//idc=507;
					idc = 189; // metric = 189, imp=616?
					style=2;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text = "3825";
					x="34.78 * 		(0.01875 * SafezoneH)";
					y="30.88 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc=152;
					style=0;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text="VIS";
					x="12.58 * 		(0.01875 * SafezoneH)";
					y="8 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc=153;
					style=0;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text="BHOT";
					x="15.78 * 		(0.01875 * SafezoneH)";
					//y="15.34 * 		(0.025 * SafezoneH)";
					y="8 * 		(0.025 * SafezoneH)";
					w="4.5 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: RangeText
				{
					idc=172; //6-digit
					//idc=504; //arty
					//text="38295461";
					font="EtelkaMonospacePro";
					style=2;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					x="12.20 * 		(0.01875 * SafezoneH)";
					y="3.5 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class TextTADS: RangeText
				{
					idc=1010;
					text="TADS";
					font="EtelkaMonospacePro";
					style=2;
					//sizeEx="0.0295*SafezoneH";
					shadow=0;
					x="12.30 * 		(0.01875 * SafezoneH)";
					y="5 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: RangeText
				{
					idc=190;
					text="20:28:35";
					font="EtelkaMonospacePro";
					style=2;
					sizeEx="0.0295*SafezoneH";
					shadow=0;
					x="12.1 * 		(0.01875 * SafezoneH)";
					y="6.5 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class CA_Laser: RscText
				{
					idc=158;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text="\DEGA_Apaches\data\Apache_LaserOn.paa";
					x="20.45 * 		(0.01875 * SafezoneH)";
					y="14.1 * 		(0.025 * SafezoneH)";
					w="12.5 * 		(0.01875 * SafezoneH)";
					h="12 * 		(0.025 * SafezoneH)";
				};
				class CA_Heading: RscText
				{
					idc=156;
					style=0;
					sizeEx="0.038*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					text="023";
					x="24.83 * 		(0.01875 * SafezoneH)";
					y="6 * 		(0.025 * SafezoneH)";
					w="4 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
};

class CfgAmmo
{
    //class Default;
    class RocketCore;
    class RocketBase;
    class BulletBase;
    class MissileCore;
    class MissileBase;
    class B_762x51_Ball;
    class B_30mm_HE;
    class B_20mm;
    class M_AT;
    class M_Scalpel_AT;
    class B_30x113mm_M789_HEDP: B_30mm_HE
    {
        hit=105;
        indirectHit=10;
        indirectHitRange=2;
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
        tracerScale=2;
        tracerStartTime=0.1;
        tracerEndTime=2.3;
        explosive=0.30000001;
        caliber=2.5;
        airFriction=-0.00078;
        laserlock=1;
        airlock=1;
        irlock=1;
        cost = 20;
        muzzleEffect = "BIS_fnc_effectFiredRifle";
        //allowAgainstInfantry=1;
    };
    class B_20mm_AP: B_20mm
    {
        hit=75;
        indirectHit=10;
        indirectHitRange=2;
        visibleFire=28;
        audibleFire=28;
        visibleFireTime=3;
        cost=20;
        airLock=1;
        irlock=1;
        explosive=0.30000001;
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
        tracerScale=1.8;
        tracerStartTime=0.1;
        tracerEndTime=2;
        airFriction=-0.00076999998;
        caliber=2.3299999;
        laserlock=1;
        muzzleEffect = "BIS_fnc_effectFiredRifle";
    };
    class M_Hellfire_AT: MissileBase
    {
        model="\DEGA_Apaches\data\Weapons\AGM114\AGM114Hellfire";
        proxyShape="\DEGA_Apaches\data\Weapons\AGM114\AGM114Hellfire_proxy";
        hit=1100;
        indirectHit=20;
        indirectHitRange=2;
        cost=1000;
        maxSpeed=425;
        irLock=1;
        laserLock=1;
        airLock=0;
        manualControl = 0;
        maxControlRange = 8000;
        trackOversteer=1;
        trackLead=1;
        maneuvrability=9;
        timeToLive=20;
        simulationStep=0.0099999998;
        sideAirFriction=0.2;
        initTime=0;
        thrustTime=3.25;
        thrust=130;
        fuseDistance=5;
        effectsMissileInit="MissileDAR1";
        effectsMissile="missile2";
        muzzleEffect = "BIS_fnc_effectFiredHeliRocket";
        weaponLockSystem="2 + 16";
        whistleDist=4;
    };
    class M_Hellfire_K_AT : M_Hellfire_AT
    {
        irlock = 0;
        hit = 1400;
        indirecthit = 200;
        indirecthitrange = 4;
        timetolive=40;  
        weaponlocksystem = 4;
        manualcontrol=0;
        lockType = 0;
        maneuvrability = 7;
        laserLock = 1;
        maxControlRange = 8000;
        maxSpeed = 1500;
        nameSound="missiles";
        cost=1000;
    };
    class M_Hellfire_N_AT : M_Hellfire_AT
    {
        irlock = 0;
        hit = 1100;
        indirecthit = 200;
        indirecthitrange = 7;
        timetolive=40;  
        weaponlocksystem = 4;
        manualcontrol=0;
        lockType = 0;
        maneuvrability = 7;
        laserLock = 1;
        maxControlRange = 8000;
        maxSpeed = 1500;
        explosionEffects = "BombExplosion";
        cost=1000;
    };
    class M_Hellfire_L_AT : M_Hellfire_AT
    {
        hit = 1400;
        indirecthit = 200;
        indirecthitrange = 4;
        timetolive=40;  
        weaponlocksystem = 8;
        manualcontrol=0;
        lockType = 0;   
        laserLock = 0;
        airLock = 0;
        irlock = 1;
        maneuvrability = 7;
        maxSpeed = 1500;
        cost=1000;
    };
    class R_Hydra_HE: M_AT
    {
        model="DEGA_Apaches\data\Weapons\70mmRocket\70mmRocket";
        hit=400;
        indirectHit=60;
        indirectHitRange=15;
        cost = 500;
        maxSpeed=740;
        thrustTime=1.1;
        thrust=570;
        sideAirFriction=0.2;
        timeToLive=20;
        fuseDistance=40;
        whistleDist=24;
        irlock=0;
        laserlock=0;
        muzzleEffect = "BIS_fnc_effectFiredHeliRocket";
    };
    class CM_US_Jammer_Ammo_Kimi: BulletBase
    {
        hit = 1;
        indirectHit = 0;
        indirectHitRange = 0;
        timeToLive = 0.1;
        thrustTime = 2.0;
        airFriction = -0.01;
        simulation = "shotCM";
        //effectsSmoke = "CounterMeasureFlare";
        weaponLockSystem = "2 + 8";
        model = "\A3\weapons_f\empty";
        maxControlRange = -1;
        initTime = 0;
    };
};
 
class CfgMagazines
{
    class VehicleMagazine;
    class CA_Magazine;
    class 100Rnd_762x51_M240_kimi: VehicleMagazine
    {
        scope=1;
        displayName="100Rnd 7.62mm M240";
        count=100;
        ammo="B_762x51_Ball";
        initSpeed=900;
        tracersEvery=4;
        lastRoundsTracer=4;
        nameSound="mgun";
        //descriptionShort="7.62mm";
    };
    class 1200Rnd_30x113mm_M789_HEDP: VehicleMagazine
    {
        scope=1;
        displayName = "HEPD";
        displayNameShort = "HEPD";
        ammo="B_30x113mm_M789_HEDP";
        count=1200;
        initSpeed=805;
        tracersEvery=1;
        maxLeadSpeed=500;
        nameSound="cannon";
        airLock=1;
    };
    class 8Rnd_Hellfire: VehicleMagazine
    {
        scope=2;
        displayName="HELLFIRE";
        count=8;
        ammo="M_Hellfire_AT";
        initSpeed=0;
        maxLeadSpeed=200;
        sound[]=
        {
            "A3\Sounds_F\weapons\Rockets\titan_3",
            1.2589254,
            1,
            1000
        };
        weaponSoundEffect="DefaultRifle";
        reloadSound[]=
        {
            "",
            0.00031622776,
            1,
            20
        };
        nameSound="missiles";
    };
    class 4Rnd_Hellfire_K : 8Rnd_Hellfire
    {
        displayName = "AGM-114K";
        displayNameShort = "SAL 2 AT";
        ammo = "M_Hellfire_K_AT";
        displayNameMagazine="SAL 2 AT";
        count = 4;
    };
    class 4Rnd_Hellfire_N: 4Rnd_Hellfire_K
    {
        displayName = "AGM-114N";
        displayNameShort = "SAL 2 Thermobaric";
        ammo = "M_Hellfire_N_AT";
        displayNameMagazine="SAL 2 Thermobaric";
    };
    class 4Rnd_Hellfire_L : 4Rnd_Hellfire_K
    {
        displayName = "AGM-114L";
        displayNameShort = "RF AT";
        ammo = "M_Hellfire_L_AT";
        displayNameMagazine="RF AT";
    };
    class 12Rnd_FFAR: VehicleMagazine
    {
        scope=2;
        ammo="R_Hydra_HE";
        count=12;
        initSpeed=44;
        maxLeadSpeed=200;
        nameSound="rockets";
        sound[]=
        {
            "DEGA_Apaches\Data\Sounds\rocketLauncher_Shot21",
            3.1622777,
            1
        };
        reloadSound[]=
        {
            "A3\sounds_f\dummysound",
            0.00031622776,
            1
        };
    };
    class 38Rnd_FFAR: 12Rnd_FFAR
    {
        displayName="FFAR (HE)";
        displayNameShort = "HE";			
        count=38;
    };
    class 38Rnd_CRV7: 12Rnd_FFAR
    {
        displayName="CRV7 (HEISAP)";
        displayNameShort = "HEISAP";		
        count=38;
    };	
    class US_Jammer_Magazine_Kimi: CA_Magazine
    {
        count = 120;
        ammo = "CM_US_Jammer_Ammo_Kimi";
        initSpeed = 30;
    };
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
    //class Default;
    class M134_minigun;
    class LauncherCore;
    class RocketPods;
    class CannonCore;
    class MissileLauncher;
    class MGun;
    class CMFlareLauncher;
    class SmokeLauncher;
    class Laserdesignator_mounted;
    class Master_Arm_Safe_US_Helos_Kimi: RocketPods
    {
        CanLock = 0;
        displayName = "SAFE";
        displayNameMagazine = "SAFE";
        shortNameMagazine = "SAFE";
        nameSound="cannon";
        cursor = "EmptyCursor";
        cursorAim = "EmptyCursor";
        magazines[] = {"FakeMagazine"};
        burst = 0;
        reloadTime = 0.01;
        magazineReloadTime = 0.1;
    };
    class Laserdesignator_mounted_Kimi_US: Laserdesignator_mounted
    {
        //cursor = "laserDesignator";
        displayName="Laser Designator";
        shotFromTurret = 1;
        cursor = "EmptyCursor";
        cursorAim = "EmptyCursor";
        nameSound = "laserdesignator";
        //cursorAimOn = "CursorAimOn";
        //cursorAimOn = "rocket";
    };
    class M134_minigun_2: M134_minigun
    {
    };
    //class gatling_30mm;
    /*class M230: gatling_30mm
    {
        displayName="M230 / 30mm HEDP";
        ballisticsComputer=2;
        magazines[]=
        {
            "1200Rnd_30x113mm_M789_HEDP"
        };
        canLock=2;
    };*/
    class M230: CannonCore
    {
        scope=1;
        displayName="M230 / 30mm HEDP";
        nameSound="cannon";
        autoFire=0;
        magazines[]=
        {
            "1200Rnd_30x113mm_M789_HEDP"
        };
        canLock=2;
        flash="gunfire";
        flashSize=0.3;
        recoil="Empty";
        ballisticsComputer=2;
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        cursorSize=1;
        shotFromTurret = 1;
        modes[]=
        {
            "Burst10",
            "Burst20",
            "LowROF",
            "close",
            "near",
            "short",
            "medium",
            "far"
        };
        class GunParticles
        {
            class Effect
            {
                effectName="machinegun"; //MachineGun2
                positionName="machinegun"; //Usti hlavne
                directionName="machinegun"; //Konec hlavne
            };
        };
        class Burst10: Mode_Burst
        {
            displayName="GUN/Burst 10";
            reloadTime=0.096;
            textureType = "semi";
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[] = {"A3\Sounds_F\weapons\30mm\30mm_st_02", 1.99526, 1, 1500};
                soundBegin[] = {"begin1", 1};
                weaponSoundEffect = "DefaultRifle";
            };
            autoFire=0; // testing AI
            burst = 10;
            soundContinuous=0;
            flash="gunfire";
            flashSize=0.3;
            recoil="Empty";
            aiDispersionCoefX=6;
            aiDispersionCoefY=6;
            ffMagnitude=0.5;
            ffFrequency=11;
            ffCount=6;
            aiRateOfFire = 0.25;
            aiRateOfFireDistance = 900;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 700;
            midRangeProbab = 0.78;
            maxRange = 900;
            maxRangeProbab = 0.2;
            dispersion=0.005;
            showToPlayer=1;
        };
        class Burst20: Mode_Burst
        {
            displayName="GUN/Burst 20";
            reloadTime=0.096;
            textureType = "burst";
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[] = {"A3\Sounds_F\weapons\30mm\30mm_st_02", 1.99526, 1, 1500};
                soundBegin[] = {"begin1", 1};
                weaponSoundEffect = "DefaultRifle";
            };
            autoFire=0;
            burst = 20;
            soundContinuous=0;
            flash="gunfire";
            flashSize=0.3;
            recoil="Empty";
            aiDispersionCoefX=6;
            aiDispersionCoefY=6;
            ffMagnitude=0.5;
            ffFrequency=11;
            ffCount=6;
            aiRateOfFire = 0.25;
            aiRateOfFireDistance = 900;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 700;
            midRangeProbab = 0.78;
            maxRange = 900;
            maxRangeProbab = 0.2;
            dispersion=0.005;
            showToPlayer=1;
        };
        class LowROF: Mode_FullAuto
        {
            displayName = "GUN/ FULL";
            reloadTime = 0.096;
            sounds[] = {"StandardSound"};
            class StandardSound
            {
                begin1[] = {"A3\Sounds_F\weapons\30mm\30mm_st_02", 1.99526, 1, 1500};
                soundBegin[] = {"begin1", 1};
                weaponSoundEffect = "DefaultRifle";
            };
            soundContinuous = 0;
            flash = "gunfire";
            flashSize = 0.1;
            recoil = "Empty";
            aiDispersionCoefX = 6;
            aiDispersionCoefY = 6;
            ffMagnitude = 0.5;
            ffFrequency = 11;
            ffCount = 6;
            minRange = 1;
            minRangeProbab = 0.90;
            midRange = 2;
            midRangeProbab = 0.90;
            maxRange = 3;
            maxRangeProbab = 0.090;
            dispersion = 0.005;
            showToPlayer = 0;
        };
        class close: LowROF
        {
            showToPlayer = 0;
            burst = 15;
            aiRateOfFire = 0.25;
            aiRateOfFireDistance = 400;
            minRange = 1;
            minRangeProbab = 0.90;
            midRange = 200;
            midRangeProbab = 0.90;
            maxRange = 400;
            maxRangeProbab = 0.90;
        };
        class near: close
        {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 0.25;
            aiRateOfFireDistance = 400;
            minRange = 1;
            minRangeProbab = 0.90;
            midRange = 150;
            midRangeProbab = 0.90;
            maxRange = 300;
            maxRangeProbab = 0.90;
        };
        class short: close
        {
            burst = 13;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.90;
            midRange = 400;
            midRangeProbab = 0.90;
            maxRange = 600;
            maxRangeProbab = 0.90;
        };
        class medium: close
        {
            burst = 9;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 900;
            minRange = 400;
            minRangeProbab = 0.90;
            midRange = 700;
            midRangeProbab = 0.90;
            maxRange = 900;
            maxRangeProbab = 0.90;
        };
        class far: close
        {
            burst = 5;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 1500;
            minRange = 800;
            minRangeProbab = 0.90;
            midRange = 1000;
            midRangeProbab = 0.90;
            maxRange = 1500;
            maxRangeProbab = 0.90;
        };
    };
    class FFARLauncher: RocketPods
    {
        magazines[]=
        {
            "38Rnd_FFAR"
        };
        modes[]=
        {
            "Far_AI",
            "Burst1",
            "Burst2",
            "Burst4"
        };
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        canLock=2;
        weaponLockDelay=0.1;
        weaponLockSystem=2;
        //ballisticsComputer=1;
        //discretedistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000};
        //discretedistanceinitindex = 3;
        //weaponInfoType="RscWeaponZeroing";
        class Far_AI: RocketPods
        {
            canLock=1;
            minRange=50;
            minRangeProbab=0.041000001;
            midRange=600;
            midRangeProbab=0.20999999;
            maxRange=2500;
            maxRangeProbab=0.11;
            displayName="HYDRA-SINGLE";
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "A3\Sounds_F\weapons\Rockets\new_rocket_8",
                    4,
                    1.2,
                    1600
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
                weaponSoundEffect="DefaultRifle";
            };
            soundFly[]=
            {
                "\A3\Sounds_F\weapons\Rockets\rocket_fly_2",
                1.1220185,
                1.2,
                700
            };
            soundContinuous=0;
            soundBurst=0;
            burst=1;
            reloadTime=0.079999998;
            autoFire=0;
            showToPlayer=0;
        };
        class Burst1: Mode_SemiAuto
        {
            minRange=1;
            minRangeProbab=0.001;
            midRange=2;
            midRangeProbab=0.001;
            maxRange=3;
            maxRangeProbab=0.01;
            displayName="M151 HEPD/Single";
            burst=1;
            canLock=1;
            reloadTime=0.15;
            autoFire=false;
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "A3\Sounds_F\weapons\Rockets\new_rocket_8",
                    4,
                    1.2,
                    1600
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
                weaponSoundEffect="DefaultRifle";
            };
            soundFly[]=
            {
                "\A3\Sounds_F\weapons\Rockets\rocket_fly_2",
                2.5,
                1.2,
                700
            };
            soundContinuous=0;
            soundBurst=0;
        };
        class Burst2: Mode_Burst
        {
            minRange=1;
            minRangeProbab=0.001;
            midRange=2;
            canLock=1;
            midRangeProbab=0.001;
            maxRange=3;
            maxRangeProbab=0.001;
            displayName="M151 HEPD/Ripple 2";
            reloadTime=0.25;
            autoFire=false;
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "A3\Sounds_F\weapons\Rockets\new_rocket_8",
                    4,
                    1.2,
                    1600
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
                weaponSoundEffect="DefaultRifle";
            };
            soundFly[]=
            {
                "\A3\Sounds_F\weapons\Rockets\rocket_fly_2",
                1.1220185,
                1.2,
                700
            };
            burst=2;
            soundContinuous=0;
            soundBurst=0;
        };
        class Burst4: Mode_FullAuto
        {
            minRange=1;
            minRangeProbab=0.001;
            midRange=2;
            midRangeProbab=0.001;
            canLock=1;
            maxRange=3;
            maxRangeProbab=0.01;
            reloadTime=0.25;
            autoFire=false;
            displayName="M151 HEPD/Ripple 4";
            burst=4;
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "A3\Sounds_F\weapons\Rockets\new_rocket_8",
                    4,
                    1.2,
                    1600
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
                weaponSoundEffect="DefaultRifle";
            };
            soundFly[]=
            {
                "\A3\Sounds_F\weapons\Rockets\rocket_fly_2",
                1.1220185,
                1.2,
                700
            };
            soundContinuous=0;
            soundBurst=0;
        };
    };
    class FFARLauncher_38_HE: FFARLauncher
    {
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        displayName="FFAR (HE)";		
        magazines[]=
        {
            "38Rnd_FFAR"
        };
    };	
    class FFARLauncher_38_HEISAP: FFARLauncher
    {
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        displayName="CRV7 (HEISAP)";		
        magazines[]=
        {
            "38Rnd_CRV7"
        };
    };		
    class HellfireLauncherK : MissileLauncher
    {
        displayName = "AGM-114K (SAL2)";
        magazines[] = {"4Rnd_Hellfire_K"};
        weaponLockDelay = 0.5;
        aiRateOfFire = 5.0;
        aiRateOfFireDistance = 4000;
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        cursorSize = 1;
        textureType = "fullAuto";
        reloadTime = 1;
        autoReload=0;
        backgroundReload=0;
        sounds[]=
        {
            "StandardSound"
        };
        class StandardSound
        {
            begin1[]=
            {
                "A3\Sounds_F\weapons\Rockets\missile_2",
                //1.1220185,
                5,
                1.3,
                1000
            };
            soundBegin[]=
            {
                "begin1",
                1
            };
            weaponSoundEffect="DefaultRifle";
        };
        soundFly[]=
        {
            "A3\Sounds_F\weapons\Rockets\rocket_fly_2",
            1,
            1.5,
            700
        };
        lockingTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_1",
            0.31622776,
            1
        };
        lockedTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_3",
            0.31622776,
            2.5
        };
    };
    class HellfireLauncherN : MissileLauncher
    {
        displayName = "AGM-114N (SAL2)";
        magazines[] = {"4Rnd_Hellfire_N"};
        weaponLockDelay = 0.5;
        aiRateOfFire = 5.0;
        aiRateOfFireDistance = 4000;
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        cursorSize = 1;
        textureType = "fullAuto";
        reloadTime = 1;
        autoReload=false;
        backgroundReload=false;
        nameSound="MissileLauncher";
        sounds[]=
        {
            "StandardSound"
        };
        class StandardSound
        {
            begin1[]=
            {
                "A3\Sounds_F\weapons\Rockets\missile_2",
                5,
                1.3,
                1000
            };
            soundBegin[]=
            {
                "begin1",
                1
            };
            weaponSoundEffect="DefaultRifle";
        };
        soundFly[]=
        {
            "A3\Sounds_F\weapons\Rockets\rocket_fly_2",
            1,
            1.5,
            700
        };
        lockingTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_1",
            0.31622776,
            1
        };
        lockedTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_3",
            0.31622776,
            2.5
        };
    };
    class HellfireLauncherL : MissileLauncher
    {
        displayName = "AGM-114L (RF)";
        magazines[] = {"4Rnd_Hellfire_L"};
        weaponLockDelay = 0.5;
        aiRateOfFire = 5.0;
        aiRateOfFireDistance = 4000;
        cursor="EmptyCursor";
        cursorAim="EmptyCursor";
        cursorSize = 1;
        textureType = "fullAuto";
        reloadTime = 1;
        autoReload=false;
        backgroundReload=false;
        nameSound="MissileLauncher";
        sounds[]=
        {
            "StandardSound"
        };
        class StandardSound
        {
            begin1[]=
            {
                "A3\Sounds_F\weapons\Rockets\missile_2",
                5,
                1.3,
                1000
            };
            soundBegin[]=
            {
                "begin1",
                1
            };
            weaponSoundEffect="DefaultRifle";
        };
        soundFly[]=
        {
            "A3\Sounds_F\weapons\Rockets\rocket_fly_2",
            1,
            1.5,
            700
        };
        lockingTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_1",
            0.31622776,
            1
        };
        lockedTargetSound[]=
        {
            "\A3\Sounds_F\weapons\Rockets\locked_3",
            0.31622776,
            2.5
        };
    };
    class KIMI_US_HELO_CMFlareLauncher: CMFlareLauncher
    {
        displayName = "Countermeasures";
        modes[] = {"Single","Burst1","Burst2","Burst3","Burst4","Burst5","Burst6","Burst7","Burst8","AIBurst"};
        cursor = "EmptyCursor";
        cursorAim = "EmptyCursor";
        class Single: Mode_SemiAuto
        {
            reloadTime=0.25;
            autoFire=false;
            displayName="A- 2F/-";
            burst=1;
            multiplier = 2;
            sounds[] = {"StandardSound"};
            class StandardSound
            {
                begin1[] = {"A3\Sounds_F\weapons\HMG\HMG_grenade",1.0,1,300};
                soundBegin[] = {"begin1",1};
                weaponSoundEffect = "DefaultRifle";
            };
        };
        class Burst1: Mode_Burst
        {
            reloadTime=0.125;
            autoFire=true;
            displayName="B - 8F/0.5S";
            burst=4;
            multiplier = 2;
            sounds[] = {"StandardSound"};
            class StandardSound
            {
                begin1[] = {"A3\Sounds_F\weapons\HMG\HMG_grenade",1.0,1,300};
                soundBegin[] = {"begin1",1};
                weaponSoundEffect = "DefaultRifle";
            };
        };
        class Burst2: Burst1
        {
            reloadTime=0.25;
            autoFire=true;
            displayName="C - 8F/1S";
            burst=4;
            multiplier = 2;
        };
        class Burst3: Burst1
        {
            reloadTime=0.5;
            autoFire=true;
            displayName="D - 8F/2S";
            burst=4;
            multiplier = 2;
        };
        class Burst4: Burst1
        {
            reloadTime=1;
            autoFire=true;
            displayName="E - 8F/4S";
            burst=4;
            multiplier = 2;
        };
        class Burst5: Burst1
        {
            reloadTime=0.125;
            autoFire=true;
            displayName="F - 16F/1S";
            burst=8;
            multiplier = 2;
        };
        class Burst6: Burst1
        {
            reloadTime=0.25;
            autoFire=true;
            displayName="G - 16F/2S";
            burst=8;
            multiplier = 2;
        };
        class Burst7: Burst1
        {
            reloadTime=0.5;
            autoFire=true;
            displayName="H - 16F/4S";
            burst=8;
            multiplier = 2;
        };
        class Burst8: Burst1
        {
            reloadTime=1;
            autoFire=true;
            displayName="I - 16F/8S";
            burst=8;
            multiplier = 2;
        };
    };
    class US_Jammer_Kimi: SmokeLauncher
    {
        scope = 2;
        displayName = "IR Jammer";
        magazines[] = {"US_Jammer_Magazine_Kimi"};
        magazineReloadTime = 60;
        simulation = "cmlauncher";
        modes[] = {"Burst1"};
        class Burst1: Mode_Burst
        {
            displayName="IR Jammer";
            reloadTime = 0.25;
            burst = 120;
            sounds[] = {"StandardSound"};
            class StandardSound
            {
                begin1[] = {/*"A3\Sounds_F\weapons\HMG\HMG_grenade"*/"",1.0,1,300};
                soundBegin[] = {"begin1",1};
                weaponSoundEffect = "";
            };
            showToPlayer = 1;
            multiplier = 1;
            minRange = 0;
            maxRange = 200;
            soundBurst = 0;
        };
    };
};


