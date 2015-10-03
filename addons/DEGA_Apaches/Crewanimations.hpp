class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		AH64_gunner_EP1="AH64_gunner_EP1";
		AH64_pilot_EP1="AH64_pilot_EP1";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		
		class AH64_gunner_EP1: Crew
		{
			file="\DEGA_Apaches\Data\Anim\AH64_gunner";
			connectTo[]=
			{
				"KIA_AH64_gunner_EP1",
				1
			};
			speed=1e+010;
		};
		class KIA_AH64_gunner_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Apaches\Data\Anim\KIA_AH64_gunner";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AH64_pilot_EP1: Crew
		{
			file="\DEGA_Apaches\Data\Anim\AH64_pilot";
			connectTo[]=
			{
				"KIA_AH64_pilot_EP1",
				1
			};
			speed=1e+010;
		};
		class KIA_AH64_pilot_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Apaches\Data\Anim\KIA_AH64_pilot";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};		
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{	
		AH64_gunner_EP1="";
		AH64_pilot_EP1="";		
	};
};