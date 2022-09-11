#pragma once

#include "Arduino.h"
#include "sdkconfig.h"

#define n_pb_coef_m_w 75
#define n_pb_coef_high_pass 455
#define n_pb_coef_low_pass 909

static double coef_low_pass[n_pb_coef_low_pass]= {2.5573634585768172e-06,9.5392181963149298e-06,1.6217566012795916e-05,2.2355189785947559e-05,2.7732217590737124e-05,3.2153703676680817e-05,3.545642785362744e-05,3.7514686188102386e-05,3.8244876217033786e-05,3.7608716541652174e-05,3.5614982644490518e-05,3.2319686883280533e-05,2.7824679527012892e-05,2.2274697978452932e-05,1.5852941475474976e-05,8.7752970567675575e-06,1.283387908689408e-06,-6.3633440678785269e-06,-1.3896274863161883e-05,-2.1046679913239752e-05,-2.7554966932809829e-05,-3.3179755870509618e-05,-3.7706500854720756e-05,-4.0955357797394472e-05,-4.2788019873971715e-05,-4.3113271069918585e-05,-4.1891044744865456e-05,-3.9134818783124013e-05,-3.4912230164618851e-05,-2.9343848241174515e-05,-2.2600105962241653e-05,-1.4896449913503593e-05,-6.4868313453185716e-06,2.3442806496453855e-06,1.1291128019813071e-05,2.003685058106398e-05,2.8264306453909421e-05,3.5667171287969698e-05,4.1960942024330677e-05,4.6893463607106894e-05,5.025460245498039e-05,5.1884708887229245e-05,5.1681541881061658e-05,4.9605372889438189e-05,4.568203990319977e-05,4.0003787009993162e-05,3.272779651072287e-05,2.4072397990691824e-05,1.4311019122094789e-05,3.7640237139262757e-06,-7.2113391708475449e-06,-1.8232578157037583e-05,-2.890483261480319e-05,-3.8834559361311645e-05,-4.7643574826574182e-05,-5.4982967527945134e-05,-6.0546384917056249e-05,-6.408220502020066e-05,-6.540412715858966e-05,-6.4399757170660824e-05,-6.103682010410766e-05,-5.5366705824278193e-05,-4.752513833584294e-05,-3.772985523988941e-05,-2.6275286592005029e-05,-1.3524329063777281e-05,1.025819421799371e-07,1.4140796532316229e-05,2.8096769710179779e-05,4.146489039747682e-05,5.3745264881725814e-05,6.4461847409123238e-05,7.3180278651910683e-05,7.9524782705195436e-05,8.3193486209240988e-05,8.3971559455555544e-05,8.1741638390882382e-05,7.6491066910994361e-05,6.8315598541593159e-05,5.741931257060796e-05,4.4110628268555761e-05,2.8794437774797772e-05,1.1960518854948012e-05,-5.8314719241491483e-06,-2.3969992091656995e-05,-4.1812037173196222e-05,-5.8705335150231008e-05,-7.4011566189015587e-05,-8.7129801776301491e-05,-9.7519324077098679e-05,-0.00010472098234354001,-0.00010837626963634886,-0.00010824335998132407,-0.0001042094322739637,-9.6298720563246662e-05,-8.4675867529220592e-05,-6.9644314783547806e-05,-5.163963498326194e-05,-3.121789088098689e-05,-9.0392890641801166e-06,1.4152425301082424e-05,3.7554218528306473e-05,6.0330898318638768e-05,8.1644230936050603e-05,0.0001006830539148254,0.00011669332636697124,0.00012900702912545164,0.00013706883568238742,0.00014045952300962007,0.00013891517832134058,0.00013234138166117365,0.0001208217014724438,0.00010462002632283517,8.4176464798067034e-05,6.0096770341150368e-05,3.3135480797409082e-05,4.1731954075810765e-06,-2.581136349268757e-05,-5.577364916289018e-05,-8.4638911892550428e-05,-0.00011133995506254551,-0.00013485572590810782,-0.00015424937309779411,-0.0001687043828586524,-0.00017755743467835132,-0.00018032669696081211,-0.00017673441095395197,-0.00016672278454942215,-0.0001504624311775164,-0.00012835283638129024,-0.00010101460773672823,-6.9273553415745588e-05,-3.4136930834371923e-05,3.2375010579007533e-06,4.1578714903141508e-05,7.9544770321220002e-05,0.00011576891120389854,0.00014890785120034989,0.0001776905716320612,0.00020096589117047809,0.00021774706275769546,0.00022725171225283623,0.00022893555471962632,0.00022251850543620808,0.00020800203867305507,0.00018567693099928707,0.0001561208483757016,0.00012018558696646317,7.89741445418521e-05,3.3808169740040592e-05,-1.381330296800875e-05,-6.2262587277968289e-05,-0.00010983800106406167,-0.00015482264352090908,-0.00019554529671517257,-0.00023044132565941565,-0.00025811139491541428,-0.00027737584061143989,-0.00028732263586131305,-0.00028734706335596752,-0.0002771814570098837,-0.00025691368791550277,-0.00022699343888730103,-0.0001882257247133922,-0.00014175155814842314,-8.9016119520089724e-05,-3.1725244507317928e-05,2.8208516255789655e-05,8.8728606804562538e-05,0.00014770392966714476,0.00020300275599635816,0.00025256855657349649,0.00029449509569784844,0.00032709808928974823,0.00034898078344835554,0.00035909096061234537,0.00035676712432959292,0.00034177194399768372,0.00031431144807679903,0.00027503892549648838,0.00022504301496864936,0.00016582001325373492,9.9230997135834226e-05,2.7444910076441179e-05,-4.7130706839059076e-05,-0.00012192917854112942,-0.00019431177705663956,-0.00026165950878027873,-0.00032146645839717413,-0.000371431408237804,-0.00040954443401443905,-0.00043416527724041875,-0.00044409051039541279,-0.00043860683811902977,-0.00041752830734208615,-0.0003812157183810188,-0.00033057712121301969,-0.00026704892701479867,-0.0001925578428202494,-0.00010946452342512695,-2.049050519207829e-05,7.136938305582282e-05,0.00016294636969276617,0.00025100560597694793,0.00033235892520460747,0.00040397861468956649,0.00046310819373069116,0.00050736620391715159,0.00053483917339928859,0.00054416021183335535,0.0005345701202786713,0.00050595844819696948,0.00045888258113678819,0.00039456367688666511,0.00031485906065045765,0.00022221151431863823,0.00011957672263987855,1.0330940750871542e-05,-0.00010183830590931036,-0.00021305501448407694,-0.00031938695992118161,-0.0004169829566539281,-0.00050221039363151151,-0.00057178819363001008,-0.00062291040075247944,-0.00065335582378010825,-0.00066157955339809268,-0.00064678271812961951,-0.00060895753114973273,-0.00054890548677880816,-0.00046822746545448657,-0.00036928546956961525,-0.00025513670707151125,-0.00012944173067836866,3.6507070971588308e-06,0.00013963854368420584,0.00027381672798296419,0.00040143802247514127,0.00051787885717825583,0.00061880451019730252,0.00070032778847187985,0.0007591554842623987,0.00079271718871046096,0.0007992715470167193,0.0007779857268780762,0.00072898472252056271,0.00065336810446798232,0.00055319291822520267,0.00043142259707955338,0.00029184294579664944,0.00013894743180585631,-2.2204853214783604e-05,-0.00018615416637183488,-0.0003472227266651617,-0.00049970894098552373,-0.00063808667933706756,-0.00075720271826921104,-0.00085246538901078838,-0.00092001762697464871,-0.000956888021587708,-0.00096111410072947684,-0.00093183293499350857,-0.00086933518815545925,-0.00077507993907665761,-0.00065166891803067665,-0.00050278019338386695,-0.000333062765428301,-0.00014799492374922388,4.6289446659689897e-05,0.00024320121524205456,0.00043591656989201406,0.00061761051042330008,0.00078169538114655323,0.00092205620993386368,0.0010332745596353097,0.0011108328248882039,0.001151291421222554,0.0011524321018506025,0.0011133616787262057,0.0010345716871898107,0.00091795097822569679,0.00076674980234311756,0.00058549561197741081,0.00037986249876374132,0.0001564978396713566,-7.7188706663993781e-05,-0.00031326729150457942,-0.00054355327230431311,-0.00075988715524185279,-0.00095441963513296117,-0.001119891908316045,-0.0012499013928984541,-0.001339143292156085,-0.0013836190774124267,-0.0013808039310364019,-0.0013297664513742852,-0.0012312354416903531,-0.0010876103369905623,-0.00090291371009301876,-0.00068268627910621714,-0.00043382684570259905,-0.00016438155808806313,0.00011671125468656203,0.00039991275601731292,0.00067540242724307715,0.00093341355031805004,0.0011645740532622072,0.0013602409995544106,0.0015128169755236503,0.0016160370091070028,0.0016652154342950214,0.001657443279405842,0.0015917282716321731,0.0014690713699375591,0.0012924758067259347,0.0010668868694237554,0.00079906301221087882,0.00049738127639074512,0.00017158233346719441,-0.0001675373337843252,-0.00050847660880451971,-0.00083941307171736621,-0.0011486059256869767,-0.0014248050150311234,-0.0016576519294040663,-0.0018380591588356367,-0.0019585537177702552,-0.0020135725869736693,-0.0019996987082443302,-0.0019158280701774835,-0.0017632605905845318,-0.0015457099657945114,-0.0012692303406261537,-0.00094206046787524722,-0.00057438887897033055,-0.00017804638104454903,0.00023386516688497899,0.00064739645824749383,0.0010482133324372731,0.0014220833293143529,0.0017553700184206934,0.0020355182871902942,0.0022515137043776245,0.0023942995826249521,0.0024571364425808799,0.0024358902057877341,0.0023292375711026075,0.0021387795981367562,0.0018690574532477346,0.0015274674771900644,0.0011240761056759922,0.00067133860398989212,0.00018372894931617596,-0.00032270860603001008,-0.00083087284294546253,-0.0013231677837395907,-0.0017820957884319079,-0.0021908620511519919,-0.002533970158583922,-0.0027977881910990592,-0.0029710653556880564,-0.0030453803362914065,-0.0030155044067434922,-0.002879664826602991,-0.0026396970612962188,-0.0023010778461170331,-0.0018728349423607472,-0.0013673334928564279,-0.00079994304274744296,-0.00018859341274919764,0.00044676844224237586,0.0010848048220905976,0.0017034779562676188,0.0022807833645845542,0.0027955023220683872,0.0032279486022029958,0.0035606842246797788,0.0037791793149928557,0.0038723924003020902,0.0038332494982008017,0.0036590031543038966,0.0033514560765901453,0.0029170381005015084,0.0023667297786093755,0.0017158307837605974,0.00098357639260031001,0.00019261041553465292,-0.00063167210635839779,-0.0014618944720341501,-0.002269558016270449,-0.0030259662253158681,-0.0037031847487274338,-0.0042750068181276624,-0.0047178925542699923,-0.0050118506057780206,-0.0051412315405879481,-0.0050954043967800615,-0.0048692907529991935,-0.0044637345281224846,-0.0038856903632341795,-0.0031482187469065409,-0.002270281864058068,-0.0012763403066884792,-0.00019575709474226377,0.00093797827819801596,0.0020881870347392566,0.003216075210292226,0.004281915359052574,0.0052463023923653039,0.0060714468293884038,0.0067224665542916446,0.0071686371363107451,0.0073845609352090301,0.0073512166051761885,0.0070568532075054643,0.0064976968915458526,0.0056784429129598307,0.0046125115025479379,0.0033220526212854951,0.0018376917547098647,0.00019801640809745326,-0.0015511893566081496,-0.0033579473787603798,-0.0051653025534743949,-0.0069127255616209431,-0.0085376659572652426,-0.0099772152170864905,-0.011169835268027865,-0.012057105149227315,-0.012585436936195644,-0.012707711924734345,-0.012384789363751425,-0.011586842722302719,-0.010294482517128525,-0.0084996300122047504,-0.0062061124927928592,-0.0034299581402303242,-0.00019937658786703538,0.0034455802029209363,0.0074536732879584506,0.011763436020177745,0.016304416397201996,0.020998673527030869,0.025762491915330928,0.030508270884532358,0.03514654118679171,0.03958805692915994,0.043745908412065611,0.047537600472552163,0.050887041459065398,0.053726390037546007,0.055997710586870066,0.057654392889574899,0.058662298024834976,0.059000599651522184,0.058662298024834983,0.057654392889574899,0.055997710586870059,0.053726390037546014,0.050887041459065398,0.047537600472552163,0.043745908412065611,0.03958805692915994,0.03514654118679171,0.030508270884532354,0.025762491915330924,0.020998673527030869,0.016304416397201999,0.011763436020177745,0.0074536732879584514,0.0034455802029209367,-0.00019937658786703548,-0.0034299581402303242,-0.0062061124927928592,-0.0084996300122047487,-0.010294482517128526,-0.011586842722302716,-0.012384789363751423,-0.012707711924734341,-0.01258543693619564,-0.012057105149227315,-0.011169835268027867,-0.009977215217086494,-0.0085376659572652409,-0.0069127255616209422,-0.0051653025534743957,-0.0033579473787603798,-0.00155118935660815,0.0001980164080974541,0.0018376917547098647,0.0033220526212854942,0.0046125115025479387,0.0056784429129598307,0.0064976968915458552,0.0070568532075054634,0.0073512166051761876,0.0073845609352090301,0.0071686371363107451,0.0067224665542916446,0.0060714468293884046,0.0052463023923653039,0.004281915359052574,0.003216075210292226,0.0020881870347392571,0.00093797827819801683,-0.00019575709474226489,-0.0012763403066884814,-0.002270281864058068,-0.0031482187469065413,-0.0038856903632341804,-0.004463734528122488,-0.0048692907529991995,-0.005095404396780058,-0.0051412315405879472,-0.0050118506057780197,-0.0047178925542699906,-0.0042750068181276642,-0.003703184748727429,-0.003025966225315869,-0.0022695580162704508,-0.0014618944720341497,-0.00063167210635839844,0.00019261041553465292,0.00098357639260030915,0.0017158307837605968,0.0023667297786093742,0.002917038100501508,0.0033514560765901457,0.003659003154303897,0.0038332494982008009,0.0038723924003020911,0.0037791793149928566,0.0035606842246797784,0.0032279486022029976,0.0027955023220683876,0.0022807833645845542,0.0017034779562676186,0.0010848048220905967,0.00044676844224237646,-0.00018859341274919886,-0.00079994304274744285,-0.0013673334928564279,-0.0018728349423607479,-0.002301077846117034,-0.0026396970612962184,-0.002879664826602991,-0.0030155044067434918,-0.0030453803362914074,-0.0029710653556880556,-0.0027977881910990592,-0.002533970158583922,-0.0021908620511519928,-0.0017820957884319077,-0.0013231677837395911,-0.00083087284294546405,-0.00032270860603001079,0.00018372894931617664,0.00067133860398989266,0.0011240761056759922,0.0015274674771900646,0.0018690574532477359,0.0021387795981367558,0.002329237571102608,0.0024358902057877341,0.0024571364425808808,0.0023942995826249521,0.0022515137043776254,0.0020355182871902942,0.0017553700184206934,0.0014220833293143529,0.0010482133324372725,0.00064739645824749264,0.00023386516688497704,-0.00017804638104454827,-0.00057438887897033142,-0.00094206046787524808,-0.0012692303406261554,-0.0015457099657945133,-0.0017632605905845314,-0.0019158280701774848,-0.0019996987082443289,-0.0020135725869736701,-0.0019585537177702552,-0.0018380591588356351,-0.0016576519294040659,-0.0014248050150311223,-0.0011486059256869774,-0.00083941307171736372,-0.00050847660880451852,-0.00016753733378432238,0.00017158233346719438,0.00049738127639074512,0.00079906301221087991,0.0010668868694237573,0.001292475806725936,0.0014690713699375604,0.0015917282716321729,0.0016574432794058422,0.0016652154342950212,0.0016160370091070028,0.001512816975523651,0.0013602409995544106,0.001164574053262207,0.00093341355031805059,0.00067540242724307737,0.00039991275601731227,0.00011671125468656245,-0.00016438155808806376,-0.00043382684570260008,-0.00068268627910621736,-0.00090291371009301985,-0.0010876103369905623,-0.0012312354416903534,-0.0013297664513742854,-0.0013808039310364022,-0.0013836190774124269,-0.0013391432921560863,-0.0012499013928984534,-0.0011198919083160452,-0.00095441963513296052,-0.00075988715524185322,-0.00054355327230431224,-0.00031326729150457893,-7.7188706663994093e-05,0.00015649783967135666,0.0003798624987637418,0.00058549561197741081,0.00076674980234311832,0.0009179509782256969,0.0010345716871898102,0.0011133616787262063,0.0011524321018506025,0.0011512914212225538,0.0011108328248882048,0.0010332745596353097,0.00092205620993386346,0.00078169538114655247,0.00061761051042330062,0.00043591656989201466,0.00024320121524205437,4.6289446659688568e-05,-0.0001479949237492236,-0.00033306276542830138,-0.00050278019338386858,-0.00065166891803067665,-0.00077507993907665706,-0.00086933518815545936,-0.00093183293499350878,-0.00096111410072947673,-0.00095688802158770887,-0.0009200176269746486,-0.00085246538901078816,-0.00075720271826921126,-0.00063808667933706507,-0.00049970894098552373,-0.00034722272666516229,-0.00018615416637183531,-2.2204853214783533e-05,0.00013894743180585661,0.00029184294579664982,0.00043142259707955387,0.00055319291822520235,0.00065336810446798242,0.00072898472252056281,0.00077798572687807631,0.00079927154701671908,0.00079271718871046096,0.00075915548426239946,0.00070032778847187909,0.00061880451019730263,0.00051787885717825615,0.00040143802247514035,0.00027381672798296446,0.00013963854368420582,3.6507070971588926e-06,-0.00012944173067836899,-0.00025513670707151223,-0.00036928546956961731,-0.0004682274654544869,-0.00054890548677880696,-0.00060895753114973241,-0.0006467827181296207,-0.00066157955339809322,-0.00065335582378010955,-0.0006229104007524802,-0.00057178819363001019,-0.0005022103936315114,-0.00041698295665392842,-0.00031938695992118183,-0.00021305501448407738,-0.00010183830590931076,1.033094075087119e-05,0.00011957672263987839,0.00022221151431863845,0.00031485906065045765,0.00039456367688666511,0.00045888258113678851,0.00050595844819696916,0.00053457012027867195,0.0005441602118333547,0.00053483917339928935,0.00050736620391715116,0.00046310819373069137,0.00040397861468956773,0.00033235892520460861,0.00025100560597694798,0.00016294636969276747,7.1369383055823539e-05,-2.0490505192078483e-05,-0.00010946452342512579,-0.00019255784282024948,-0.00026704892701479938,-0.00033057712121301974,-0.00038121571838101967,-0.00041752830734208664,-0.0004386068381190302,-0.00044409051039541279,-0.00043416527724041956,-0.00040954443401443861,-0.0003714314082378034,-0.00032146645839717391,-0.00026165950878027846,-0.00019431177705663978,-0.000121929178541129,-4.7130706839058954e-05,2.7444910076441145e-05,9.923099713583424e-05,0.00016582001325373495,0.00022504301496864969,0.0002750389254964886,0.00031431144807679914,0.00034177194399768427,0.00035676712432959292,0.00035909096061234537,0.00034898078344835571,0.0003270980892897484,0.00029449509569784898,0.00025256855657349671,0.00020300275599635848,0.00014770392966714487,8.8728606804562945e-05,2.8208516255789859e-05,-3.1725244507317942e-05,-8.9016119520089792e-05,-0.0001417515581484232,-0.00018822572471339184,-0.00022699343888730108,-0.00025691368791550304,-0.00027718145700988354,-0.00028734706335596742,-0.00028732263586131343,-0.00027737584061144011,-0.00025811139491541401,-0.00023044132565941565,-0.00019554529671517255,-0.00015482264352090924,-0.00010983800106406174,-6.2262587277968343e-05,-1.3813302968008714e-05,3.3808169740040707e-05,7.8974144541852005e-05,0.00012018558696646339,0.00015612084837570185,0.0001856769309992872,0.00020800203867305488,0.0002225185054362081,0.00022893555471962645,0.00022725171225283582,0.0002177470627576953,0.00020096589117047869,0.00017769057163206077,0.00014890785120035013,0.00011576891120389864,7.9544770321220422e-05,4.1578714903141508e-05,3.2375010579003429e-06,-3.4136930834371869e-05,-6.9273553415745548e-05,-0.00010101460773672808,-0.00012835283638129073,-0.00015046243117751616,-0.00016672278454942215,-0.00017673441095395219,-0.00018032669696081252,-0.00017755743467835124,-0.00016870438285865232,-0.00015424937309779405,-0.00013485572590810803,-0.00011133995506254558,-8.4638911892550577e-05,-5.5773649162890146e-05,-2.5811363492687549e-05,4.1731954075810621e-06,3.3135480797409061e-05,6.0096770341150571e-05,8.4176464798067075e-05,0.00010462002632283512,0.00012082170147244393,0.00013234138166117376,0.00013891517832134107,0.00014045952300962021,0.00013706883568238742,0.00012900702912545172,0.00011669332636697133,0.00010068305391482529,8.1644230936050779e-05,6.0330898318638822e-05,3.7554218528306541e-05,1.4152425301082381e-05,-9.0392890641801098e-06,-3.1217890880987107e-05,-5.1639634983261513e-05,-6.9644314783547426e-05,-8.46758675292207e-05,-9.6298720563246513e-05,-0.00010420943227396358,-0.0001082433599813241,-0.00010837626963634887,-0.00010472098234353998,-9.7519324077098652e-05,-8.7129801776301573e-05,-7.4011566189015749e-05,-5.8705335150230933e-05,-4.1812037173196147e-05,-2.396999209165706e-05,-5.8314719241491636e-06,1.1960518854947844e-05,2.8794437774797891e-05,4.4110628268555801e-05,5.7419312570607642e-05,6.8315598541593349e-05,7.6491066910994171e-05,8.1741638390882531e-05,8.3971559455555544e-05,8.3193486209241055e-05,7.9524782705195775e-05,7.3180278651910506e-05,6.4461847409123346e-05,5.3745264881725841e-05,4.1464890397476474e-05,2.8096769710179894e-05,1.4140796532316291e-05,1.0258194217985446e-07,-1.352432906377733e-05,-2.6275286592005253e-05,-3.7729855239889498e-05,-4.7525138335843109e-05,-5.5366705824278132e-05,-6.1036820104107471e-05,-6.4399757170661013e-05,-6.540412715858966e-05,-6.408220502020066e-05,-6.0546384917056256e-05,-5.4982967527945216e-05,-4.7643574826574223e-05,-3.883455936131157e-05,-2.8904832614803183e-05,-1.8232578157037627e-05,-7.2113391708475237e-06,3.7640237139262951e-06,1.431101912209485e-05,2.4072397990691919e-05,3.272779651072283e-05,4.0003787009993108e-05,4.5682039903199818e-05,4.9605372889438081e-05,5.1681541881061603e-05,5.1884708887229258e-05,5.0254602454980478e-05,4.6893463607106785e-05,4.1960942024330677e-05,3.566717128796984e-05,2.826430645390934e-05,2.0036850581064024e-05,1.1291128019813142e-05,2.3442806496453952e-06,-6.4868313453185877e-06,-1.4896449913503474e-05,-2.260010596224163e-05,-2.9343848241174427e-05,-3.491223016461879e-05,-3.9134818783124046e-05,-4.1891044744865395e-05,-4.3113271069918538e-05,-4.2788019873971742e-05,-4.0955357797394526e-05,-3.7706500854720763e-05,-3.3179755870509577e-05,-2.7554966932809856e-05,-2.1046679913239769e-05,-1.3896274863161928e-05,-6.3633440678785354e-06,1.2833879086894171e-06,8.7752970567675372e-06,1.5852941475474858e-05,2.2274697978452874e-05,2.7824679527012892e-05,3.2319686883280628e-05,3.5614982644490511e-05,3.7608716541652276e-05,3.824487621703378e-05,3.7514686188102447e-05,3.545642785362744e-05,3.2153703676680688e-05,2.7732217590737201e-05,2.2355189785947247e-05,1.6217566012795638e-05,9.5392181963150162e-06,2.5573634585766178e-06};
static double coef_high_pass[n_pb_coef_high_pass] = {-8.2981992440261127e-05,-7.9809744576156557e-05,-7.6402312042643845e-05,-7.2755365816370852e-05,-6.8863791915760921e-05,-6.4721801632817207e-05,-6.0323056719747041e-05,-5.5660808755985589e-05,-5.0728051796452665e-05,-4.5517687281130327e-05,-4.0022700070135723e-05,-3.4236344358172791e-05,-2.8152338118394791e-05,-2.1765064629021511e-05,-1.5069779547284564e-05,-8.0628219150946052e-06,-7.4182740988707224e-07,6.8940579069815208e-06,1.4843965142606423e-05,2.3105093263788727e-05,3.1672504793730434e-05,4.053892839746156e-05,4.96945702439807e-05,5.9126936025483809e-05,6.8820665493985896e-05,7.8757381342970255e-05,8.8915554216413158e-05,9.9270385569644846e-05,0.00010979371003613461,0.00012045391887161617,0.0001312159059522423,0.00014204103769702481,0.00015288714816706609,0.00016370856046551743,0.0001744561354233295,0.00018507734840734932,0.0001955163949298096,0.00020571432557251238,0.00021560921056587145,0.00022513633418323614,0.00023422841892557371,0.00024281587928154928,0.00025082710465433995,0.0002581887708502002,0.00026482617932594717,0.00027066362319425009,0.00027562477878804325,0.00027963312138966606,0.00028261236353764011,0.00028448691413547692,0.00028518235640373973,0.0002846259425399088,0.00028274710278155678,0.00027947796640805951,0.00027475389206561498,0.00026851400466080345,0.00026070173594028171,0.00025126536575945189,0.0002401585609419934,0.00022734090854584061,0.00021277844028034091,0.00019644414476465503,0.00017831846427961159,0.00015838977264477527,0.00013665483084993716,0.0001131192170859618,8.7797727854268569e-05,6.0714746887389692e-05,3.1904578685151926e-05,1.4117435621436168e-06,-3.0708768787938818e-05,-6.4391290076687457e-05,-9.9559311272651656e-05,-0.00013612537007353647,-0.0001739909903693952,-0.00021304667586744805,-0.00025317195983300171,-0.00029423551266924994,-0.0003360953088123391,-0.00037859885415797938,-0.00042158347496311073,-0.00046487666888181861,-0.00050829651850006036,-0.0005516521674301055,-0.00059474435871423206,-0.00063736603496962637,-0.00067930299938403756,-0.00072033463634608541,-0.00076023469016677642,-0.00079877210002135622,-0.00083571188891473289,-0.00087081610415101947,-0.00090384480646990442,-0.0009345571047012618,-0.0009627122324862914,-0.00098807066332021361,-0.0010103952598897409,-0.0010294524534098179,-0.0010450134484100279,-0.0010568554481831306,-0.0010647628958878393,-0.0010685287260966444,-0.0010679556213984906,-0.0010628572685067266,-0.0010530596081860921,-0.001038402073199706,-0.0010187388083889967,-0.00099393986693717992,-0.00096389237683098443,-0.0009285016715264927,-0.00088769237884374851,-0.0008414094621615382,-0.00078961920805882796,-0.0007323101546527766,-0.00066949395501514895,-0.0006012061702091202,-0.00052750698667668183,-0.00044848185292270125,-0.00036424203068460484,-0.00027492505604603297,-0.00018069510624775157,-8.1743268268771204e-05,2.1712294406151603e-05,0.00012942628005079064,0.0002411262948249233,0.00035651300918998859,0.00047526042661341308,0.0005970162661210588,0.00072140245980153626,0.0008480157658975159,0.00097642849763959272,0.0011061893674897431,0.0012368244459659934,0.0013678382337196772,0.0014987148450339922,0.0016289193004092512,0.0017578989253990468,0.0018850848523643082,0.002009893621321483,0.0021317288755789638,0.0022499831473846979,0.0023640397283499256,0.0024732746189713309,0.0025770585511487769,0.0026747590771903263,0.0027657427184124058,0.0028493771660828187,0.0029250335271196483,0.0029920886066517262,0.0030499272192680013,0.0030979445205353119,0.0031355483501483285,0.0031621615778929103,0.0031772244434563096,0.0031801968810051982,0.0031705608193767433,0.0031478224486892231,0.0031115144441779181,0.0030611981380993976,0.0029964656306232227,0.0029169418307446239,0.0028222864184047113,0.0027121957191960713,0.0025864044832607743,0.0024446875602541543,0.0022868614625507345,0.0021127858092070129,0.0019223646435689295,0.0017155476178179491,0.0014923310381877327,0.0012527587650516981,0.00099692296257858771,0.00072496469317679063,0.00043707435249642563,0.00013349194132925753,-0.00018549282866214606,-0.00051954059784500904,-0.00086826259198046298,-0.0012312210272464946,-0.0016079296874659461,-0.0019978546734286881,-0.0024004153235347094,-0.002814985304319906,-0.0032408938687615604,-0.0036774272795987301,-0.0041238303942466971,-0.0045793084072371093,-0.0050430287454792397,-0.0055141231110155363,-0.0059916896653391203,-0.0064747953487547215,-0.0069624783277000956,-0.0074537505624050577,-0.0079476004867520007,-0.0084429957917173774,-0.0089388863033207557,-0.0094342069455879661,-0.0099278807786503005,-0.010418822101753834,-0.010905939610643655,-0.011388139598518501,-0.011864329189523294,-0.012333419593561467,-0.012794329371066773,-0.013245987696276188,-0.013687337607492184,-0.01411733923281441,-0.014534972979857922,-0.014939242678057574,-0.015329178662285786,-0.015703840786683281,-0.01606232135781905,-0.016403747976555909,-0.016727286278300592,-0.017032142561661481,-0.017317566295921103,-0.017582852498153452,-0.017827343971275937,-0.018050433394820629,-0.018251565260737984,-0.018430237647105274,-0.018586003823200418,-0.018718473680016782,-0.018827314980933194,-0.01891225442791403,-0.018973078539293385,-0.019009634335892627,0.98089366035800374,-0.019009634335892627,-0.018973078539293389,-0.018912254427914027,-0.018827314980933194,-0.018718473680016782,-0.018586003823200418,-0.018430237647105274,-0.018251565260737984,-0.018050433394820629,-0.017827343971275937,-0.017582852498153452,-0.0173175662959211,-0.017032142561661478,-0.016727286278300592,-0.016403747976555909,-0.01606232135781905,-0.015703840786683278,-0.015329178662285786,-0.014939242678057574,-0.014534972979857921,-0.01411733923281441,-0.013687337607492184,-0.013245987696276187,-0.012794329371066771,-0.012333419593561467,-0.011864329189523291,-0.011388139598518501,-0.010905939610643654,-0.010418822101753832,-0.0099278807786503023,-0.0094342069455879661,-0.0089388863033207575,-0.0084429957917173792,-0.0079476004867519989,-0.0074537505624050586,-0.0069624783277000956,-0.0064747953487547206,-0.0059916896653391194,-0.0055141231110155354,-0.0050430287454792415,-0.0045793084072371093,-0.0041238303942466954,-0.0036774272795987314,-0.0032408938687615604,-0.0028149853043199051,-0.0024004153235347098,-0.0019978546734286877,-0.0016079296874659476,-0.001231221027246495,-0.00086826259198046385,-0.00051954059784501013,-0.00018549282866214703,0.0001334919413292568,0.00043707435249642704,0.00072496469317679302,0.00099692296257858685,0.0012527587650516985,0.0014923310381877342,0.0017155476178179494,0.0019223646435689301,0.0021127858092070133,0.0022868614625507345,0.0024446875602541543,0.0025864044832607743,0.0027121957191960726,0.0028222864184047122,0.0029169418307446239,0.0029964656306232236,0.0030611981380993976,0.0031115144441779181,0.0031478224486892218,0.0031705608193767429,0.0031801968810051999,0.0031772244434563105,0.0031621615778929112,0.0031355483501483285,0.0030979445205353124,0.0030499272192680009,0.0029920886066517258,0.0029250335271196488,0.0028493771660828191,0.0027657427184124062,0.0026747590771903267,0.0025770585511487765,0.0024732746189713305,0.0023640397283499264,0.0022499831473846987,0.0021317288755789642,0.002009893621321483,0.0018850848523643082,0.0017578989253990466,0.0016289193004092512,0.0014987148450339919,0.0013678382337196772,0.001236824445965994,0.0011061893674897433,0.00097642849763959316,0.00084801576589751677,0.00072140245980153723,0.00059701626612105891,0.00047526042661341341,0.00035651300918998892,0.00024112629482492373,0.00012942628005079126,2.1712294406151796e-05,-8.174326826877092e-05,-0.00018069510624775149,-0.00027492505604603335,-0.000364242030684605,-0.00044848185292270152,-0.00052750698667668183,-0.00060120617020912042,-0.00066949395501514895,-0.00073231015465277725,-0.00078961920805882817,-0.00084140946216153787,-0.00088769237884374851,-0.00092850167152649292,-0.00096389237683098476,-0.00099393986693717927,-0.0010187388083889972,-0.0010384020731997066,-0.0010530596081860921,-0.001062857268506727,-0.0010679556213984915,-0.0010685287260966438,-0.0010647628958878389,-0.001056855448183131,-0.0010450134484100279,-0.0010294524534098187,-0.0010103952598897415,-0.00098807066332021469,-0.00096271223248629151,-0.00093455710470126266,-0.00090384480646990518,-0.00087081610415101914,-0.00083571188891473354,-0.00079877210002135633,-0.00076023469016677663,-0.00072033463634608563,-0.00067930299938403832,-0.00063736603496962615,-0.0005947443587142325,-0.00055165216743010583,-0.00050829651850006102,-0.00046487666888181888,-0.00042158347496311095,-0.00037859885415797971,-0.0003360953088123391,-0.00029423551266925037,-0.00025317195983300193,-0.00021304667586744826,-0.00017399099036939547,-0.00013612537007353669,-9.9559311272651724e-05,-6.4391290076687646e-05,-3.0708768787938771e-05,1.4117435621433699e-06,3.1904578685152055e-05,6.0714746887389692e-05,8.7797727854268596e-05,0.00011311921708596184,0.00013665483084993716,0.00015838977264477541,0.00017831846427961173,0.00019644414476465512,0.00021277844028034113,0.00022734090854584061,0.00024015856094199346,0.00025126536575945205,0.00026070173594028154,0.00026851400466080372,0.00027475389206561488,0.00027947796640805973,0.00028274710278155667,0.00028462594253990912,0.00028518235640374,0.0002844869141354773,0.00028261236353764027,0.00027963312138966606,0.0002756247787880432,0.00027066362319425014,0.0002648261793259475,0.00025818877085020004,0.00025082710465434001,0.00024281587928154952,0.00023422841892557409,0.00022513633418323609,0.00021560921056587142,0.00020571432557251257,0.00019551639492980947,0.0001850773484073494,0.00017445613542332945,0.00016370856046551751,0.00015288714816706606,0.00014204103769702476,0.0001312159059522423,0.00012045391887161635,0.00010979371003613469,9.9270385569644914e-05,8.8915554216413252e-05,7.87573813429702e-05,6.8820665493986004e-05,5.9126936025483823e-05,4.969457024398074e-05,4.0538928397461553e-05,3.1672504793730285e-05,2.3105093263788717e-05,1.4843965142606452e-05,6.894057906981575e-06,-7.4182740988702226e-07,-8.0628219150946001e-06,-1.5069779547284593e-05,-2.1765064629021348e-05,-2.8152338118394727e-05,-3.4236344358172764e-05,-4.0022700070135614e-05,-4.5517687281130327e-05,-5.0728051796452597e-05,-5.5660808755985636e-05,-6.032305671974698e-05,-6.4721801632817112e-05,-6.886379191576084e-05,-7.2755365816370852e-05,-7.6402312042643872e-05,-7.9809744576156666e-05,-8.2981992440261086e-05};
static double coef_mw [75] = {0};

static double hist_high_pass[n_pb_coef_high_pass] = {0};  //storico valori
static double hist_low_pass[n_pb_coef_low_pass] = {0};  //storico valori
static double hist_mw[n_pb_coef_m_w] = {0};

void inizializate_mw();

double mowing_windows_average_filter(double);

double low_pass_filter(double);

double high_pass_filter(double);

double  fir_filter_r(double,double*,int,double[]);
