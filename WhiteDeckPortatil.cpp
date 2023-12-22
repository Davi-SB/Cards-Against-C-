#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#define cartas_mao 6
using namespace std;

void LoadDeck(vector<string>& vec) {
    string line;
    ifstream file("WhiteDeck.txt");
    if(!file.is_open()) { cout << "Erro em abrir arquivo" << endl; exit(1);}
    while (getline(file, line)) {
        vec.push_back(line);
        line.clear();
    } 
}

void LoadDeckPORTATIL(vector<string>& vec);

int main() {
    srand(time(nullptr));

    vector<string> vec_deck;
    string deck_mao[cartas_mao]={};
    int choice = 0, rand_i, cont=0;
    bool next = true;

    string str_num;
    int index_choice, num;
    bool run = true; 
    bool repeated = false;

    LoadDeckPORTATIL(vec_deck); // carrega as cartas para vec_deck
    
    for (int j = 0; j < cartas_mao; j++) {
        rand_i = rand() % (vec_deck.size());
        deck_mao[j] = vec_deck[rand_i];
    }
    
    while (next) {
        cout << endl << "\t\t- - - - - | C++ Against Humanity | - - - - -" << endl << endl;
        cout << "\tSeu baralho:" << endl;
        for(string x : deck_mao) {
            cout << x << endl;
        }
        run = true;
        cout << "Insira o numero da carta escolhida: ";
        cin >> choice; cin.ignore();

        if(choice>=0) {   
            for (int k = 0; (k < cartas_mao) && run; k++) {   
                
                str_num = deck_mao[k].substr(0, 3); // comecando do 0, extrai 3
                num = stoi(str_num);
                //cout << str_num << "  " << num << endl;

                if(num == choice) {
                    index_choice = k;
                    //cout << k << "  " << index_choice << endl;
                    run = false;
                }
            }

            if(!run){
                cout << endl << "--- " << deck_mao[index_choice] << " ---" << endl << endl;

                repeated = true;
                while (repeated) {
                    rand_i = rand() % (vec_deck.size());
                    
                    repeated = false;
                    for (int k = 0; k < cartas_mao; k++) {
                        if(vec_deck[rand_i] == deck_mao[k]) repeated = true;
                    }
                }
                
                deck_mao[index_choice].clear();
                deck_mao[index_choice] = vec_deck[rand_i];
                cout << "Pressione <ENTER> quando a votacao terminar. . ." << endl;
                cin.ignore(10, '\n'); // pause
                cont++;
                system("clear");
            }
        }
        else { next = false; }
    }
    
    cout << "Jogo finalizado! " << cont << " cartas foram jogadas por voce! Jantou" << endl << endl;
    return 0;
}

void LoadDeckPORTATIL(vector<string>& vec) {
    vec.push_back("000. CZAR.");
    vec.push_back("001. Um momento  de silencio. ");
    vec.push_back("002. Um festival da linguica. ");
    vec.push_back("003. Um policial honesto sem nada a perder. ");
    vec.push_back("004. Escassez de comida. ");
    vec.push_back("005. Bacteria carnivora. ");
    vec.push_back("006. Erva para aumentar a libido. ");
    vec.push_back("007. Nao dar a minima para o Terceiro Mundo. ");
    vec.push_back("008. Sexting. ");
    vec.push_back("009. Transmutacao corporea. ");
    vec.push_back("010. Atrizes porno.  ");
    vec.push_back("011. 72 virgens. ");
    vec.push_back("012. Fuzilamento. ");
    vec.push_back("013. Um paradoxo de viagem no tempo. ");
    vec.push_back("014. Autentica cozinha mexicana. ");
    vec.push_back("015. Cintilante. ");
    vec.push_back("016. Consultores. ");
    vec.push_back("017. Divida monstruosa.  ");
    vec.push_back("018. Cotas raciais. ");
    vec.push_back("019. Deixar o lustre cair sobre seus inimigos enquanto a outra ponta da corda te lanca pra cima. ");
    vec.push_back("020. O ex-presidente Lula. ");
    vec.push_back("021. Nudez frontal. ");
    vec.push_back("022. Injecões hormonais. ");
    vec.push_back("023. Por um ovo. ");
    vec.push_back("024. Assistir Cartoon Network pelado(a). ");
    vec.push_back("025. Fingir que se importa. ");
    vec.push_back("026. Pagar mico em publico. ");
    vec.push_back("027. Compartilhar agulhas. ");
    vec.push_back("028. Meleca de nariz. ");
    vec.push_back("029. A inevitavel morte termica do universo. ");
    vec.push_back("030. O milagre do parto. ");
    vec.push_back("031. O apocalise. ");
    vec.push_back("032. Passar o rodo. ");
    vec.push_back("033. O privilegio de ser branco. ");
    vec.push_back("034. Deveres da esposa. ");
    vec.push_back("035. Uma viagem para Pelotas. ");
    vec.push_back("036. Desodorante AXE. ");
    vec.push_back("037. O sangue de Cristo. ");
    vec.push_back("038. Horriveis acidentes causados por depilacao a laser. ");
    vec.push_back("039. BATMAN!!!.");
    vec.push_back("040. Agricultura. ");
    vec.push_back("041. Um mongoloide vigoroso. ");
    vec.push_back("042. Selecao natural. ");
    vec.push_back("043. Aborto clandestino. ");
    vec.push_back("044. Comer todos os doces que deveriam ser vendidos na campanha de caridade. ");
    vec.push_back("045. Os bracos da Michelle Obama. ");
    vec.push_back("046. O jogo World of Warcraft. ");
    vec.push_back("047. Cobicar a mulher do proximo. ");
    vec.push_back("048. Obesidade. ");
    vec.push_back("049. Um clipe homo-erotico sobre voleibol. ");
    vec.push_back("050. Tetano. ");
    vec.push_back("051. Exibicao para fins de acasalamento. ");
    vec.push_back("052. Torcao testicular. ");
    vec.push_back("053. Buffet de camarao livre por 4,99. ");
    vec.push_back("054. Feijoada. ");
    vec.push_back("055. Kanye West. ");
    vec.push_back("056. Queijo quente. ");
    vec.push_back("057. Ataques de velociraptor. ");
    vec.push_back("058. Tirar a camisa. ");
    vec.push_back("059. Esmegma. ");
    vec.push_back("060. Alcoholismo. ");
    vec.push_back("061. Um cara de meia idade andando de patins. ");
    vec.push_back("062. Os raios de sentimentos bons dos Ursinhos Carinhosos. ");
    vec.push_back("063. Empanturrar-se e purgar-se. ");
    vec.push_back("064. Pirulitos gigantes. ");
    vec.push_back("065. Auto-repugnancia. ");
    vec.push_back("066. Criancas na coleira. ");
    vec.push_back("067. Preliminares meia-boca. ");
    vec.push_back("069. Porno calabouco- alemao. ");
    vec.push_back("070. Estar em chamas. ");
    vec.push_back("071. Gravidez na adolescencia. ");
    vec.push_back("072. Deixar uma mensagem de voz esquisita. ");
    vec.push_back("073. Uppercuts. ");
    vec.push_back("074. Funcionarios do servico de atendimento ao cliente. ");
    vec.push_back("075. Uma erecao que dura mais que quatro horas. ");
    vec.push_back("076. Minha genitalia. ");
    vec.push_back("077. Pegar mulher na clinica de aborto. ");
    vec.push_back("078. Ciencia. ");
    vec.push_back("079. Sexo oral nao reciproco. ");
    vec.push_back("080. Aves que nao voam. ");
    vec.push_back("081. Uma boa cheirada. ");
    vec.push_back("082. Afogamento simulado. ");
    vec.push_back("083. Cafe da manha balanceado. ");
    vec.push_back("084. Faculdades historicamente mais frequentadas por gays. ");
    vec.push_back("085. Literalmente roubar doce de crianca. ");
    vec.push_back("086. A fundacao Airton Sena.");
    vec.push_back("087. Um arranhao no traseiro mantido em segredo. ");
    vec.push_back("088. Notas passivo- agressivas no trabalho. ");
    vec.push_back("089. O time de ginastica chines. ");
    vec.push_back("090. Depender do SUS. ");
    vec.push_back("091. Mijar um pouco. ");
    vec.push_back("092. Capitao Nascimento levando bronca da sogra. ");
    vec.push_back("093. Polucao noturna. ");
    vec.push_back("094. Os judeus. ");
    vec.push_back("095. Minhas curvas. ");
    vec.push_back("096. Coisas poderosas. ");
    vec.push_back("097. Piscar para idosos. ");
    vec.push_back("098. Reporteres de programa humoristico. ");
    vec.push_back("099. Uma caricia suave na parte interna da coxa. ");
    vec.push_back("100. Tensao sexual. ");
    vec.push_back("101. O fruto proibido. ");
    vec.push_back("102. Esqueleto. ");
    vec.push_back("103. Churrasco na lage. ");
    vec.push_back("104. Ser rico. ");
    vec.push_back("105. Doce, doce vinganca. ");
    vec.push_back("106. Republicanos. ");
    vec.push_back("107. Um antilope flatulento. ");
    vec.push_back("108. Natalie Portman. ");
    vec.push_back("109. Acariciar alguem sem permissao. ");
    vec.push_back("110. Pilotos Kamikaze. ");
    vec.push_back("111. Sean Connery. ");
    vec.push_back("112. A agenda homossexual. ");
    vec.push_back("113. O Mexicano que trabalha duro. ");
    vec.push_back("114. Um falcao emcapuzado. ");
    vec.push_back("115. O cara da previsao do tempo. ");
    vec.push_back("116. Ficar tao nervoso a ponto de ter uma erecao. ");
    vec.push_back("117. Amostras gratis. ");
    vec.push_back("118. Um grande estardalhaco por nada. ");
    vec.push_back("119. Fazer a coisa certa. ");
    vec.push_back("120. O jeitinho brasileiro. ");
    vec.push_back("121. Lactacao. ");
    vec.push_back("122. Paz mundial. ");
    vec.push_back("123. RoboCop. ");
    vec.push_back("124. Senvergonhice. ");
    vec.push_back("125. Justin Bieber. ");
    vec.push_back("126. Oompa-Loompas. ");
    vec.push_back("127. Cantar a tirolesa inapropriadamente,. ");
    vec.push_back("128. Puberdade. ");
    vec.push_back("129. Fantasmas. ");
    vec.push_back("130. Implantes de silicone assimetricos. ");
    vec.push_back("131. Axe Music. ");
    vec.push_back("132. Masturbacao Dinheiro na Sacole. Brutalidade ");
    vec.push_back("133. feminina. cueca. policial. ");
    vec.push_back("134. Flanelinhas. ");
    vec.push_back("135. Pre-adolescentes. ");
    vec.push_back("136. Escalpeamento. ");
    vec.push_back("137. Deixar escapar uma risadinha a mencao de Tutsis e Hutus. ");
    vec.push_back("138. Twittar. ");
    vec.push_back("139. Darth Vader. ");
    vec.push_back("140. Uma masturbacao triste. ");
    vec.push_back("141. Justamente o que voce esperaria. ");
    vec.push_back("142. Esperar um arroto e acabar vomitando no chao. ");
    vec.push_back("143. Gardenal. ");
    vec.push_back("144. Celulas tronco. ");
    vec.push_back("145. Vestir-se de modo a exibir a lateral dos seios com elegancia. ");
    vec.push_back("146. Sexo entre pandas. ");
    vec.push_back("147. Lobotomia. ");
    vec.push_back("148. Tom Cruise. ");
    vec.push_back("149. Herpes bucal. ");
    vec.push_back("150. Cachalotes. ");
    vec.push_back("151. Moradores de rua. ");
    vec.push_back("152. Dar uns amassos. ");
    vec.push_back("153. Incesto. ");
    vec.push_back("154. Ejaculacao precoce. ");
    vec.push_back("155. Um mimico tendo um AVC. ");
    vec.push_back("156. Hulk Hogan. ");
    vec.push_back("157. Cocar sob as dobras da pele. ");
    vec.push_back("158. Emocões. ");
    vec.push_back("159. Lamber coisas para estabelecer que sao propriedade sua. ");
    vec.push_back("160. Cerveja quente. ");
    vec.push_back("161. A placenta. ");
    vec.push_back("162. Combustao humana espontanea. ");
    vec.push_back("163. Amizade colorida. ");
    vec.push_back("164. Pintar com os dedos. ");
    vec.push_back("165. Cheiro de pessoa velha. ");
    vec.push_back("166. Morrer de disenteria. ");
    vec.push_back("167. Meus demonios interiores. ");
    vec.push_back("168. Pistola d'agua cheia de urina de gato. ");
    vec.push_back("169. Aaron Burr. ");
    vec.push_back("170. Chamego. ");
    vec.push_back("171. A cronica. ");
    vec.push_back("172. Rinha de galo. ");
    vec.push_back("173. Fogo amigo. ");
    vec.push_back("174. Ronald Reagan. ");
    vec.push_back("175. Uma festa de aniversario decepcionante. ");
    vec.push_back("176. Uma negra atrevida. ");
    vec.push_back("177. Atleta de olimpiada de matematica. ");
    vec.push_back("178. Um cavalo minusculo. ");
    vec.push_back("179. William Shatner. ");
    vec.push_back("180. Cavalgar rumo ao por do sol. ");
    vec.push_back("181. Uma reviravolta num roteiro de M. Night ");
    vec.push_back("182. Shyamalan. ");
    vec.push_back("183. Judeu de cabelo afro. ");
    vec.push_back("184. Destruicao Mutua Assegurada (MAD). ");
    vec.push_back("185. Pedofilos. ");
    vec.push_back("186. Fungos. ");
    vec.push_back("187. Roubar sepultura. ");
    vec.push_back("188. Comer o ultimo bisao conhecido. ");
    vec.push_back("189. Catapultas. ");
    vec.push_back("190. Os pobres. ");
    vec.push_back("191. O Doce Veneno do Escorpiao. ");
    vec.push_back("192. Funk Proibidao. ");
    vec.push_back("193. A Forca. ");
    vec.push_back("194. Limpar a bunda dela. ");
    vec.push_back("195. Design Inteligente. ");
    vec.push_back("196. Lingua solta. ");
    vec.push_back("197. AIDS. ");
    vec.push_back("198. Imagens de seios. ");
    vec.push_back("199. O ubermensch. ");
    vec.push_back("200. Sarah Palin. ");
    vec.push_back("201. Legiao dos Super-Herois Brasileiros. ");
    vec.push_back("202. Ficar completamente dopado. ");
    vec.push_back("203. Cientologia. ");
    vec.push_back("204. Inveja do penis. ");
    vec.push_back("205. Rezar pra curar homossexualismo. ");
    vec.push_back("206. Flertar. ");
    vec.push_back("207. Dois anões cagando num balde. ");
    vec.push_back("208. A Ku Klux Klan. ");
    vec.push_back("209. Genghis Khan. ");
    vec.push_back("210. Metanfetamina. ");
    vec.push_back("211. Servidao. ");
    vec.push_back("212. Perigo relacionado a pessoas estranhas. ");
    vec.push_back("213. Um brinquedo Bop It'Y“, A carreira de ator do Shaquille O'Neal. ");
    vec.push_back("214. Exibir-se. ");
    vec.push_back("215. Milicias. ");
    vec.push_back("216. Sobrecompensacao. ");
    vec.push_back("217. Cena de “bukkake” em baixa resolucao. ");
    vec.push_back("218. Uma vida de tristeza. ");
    vec.push_back("219. Racismo. ");
    vec.push_back("220. Arremesso de anao. ");
    vec.push_back("221. Felicidade ingenua. ");
    vec.push_back("222. Um macaco fumando cigarro. ");
    vec.push_back("223. Inundacao. ");
    vec.push_back("224. O testiculo ausente em Lance Armstrong. ");
    vec.push_back("225. ansia de vomito. ");
    vec.push_back("226. Terroristas. ");
    vec.push_back("227. Britney Spears aos 55. ");
    vec.push_back("228. Atitude. ");
    vec.push_back("229. Subitamente cantar e dancar uma cancao em publico. ");
    vec.push_back("230. Lepra. ");
    vec.push_back("231. Buracos gloriosos. ");
    vec.push_back("232. Mamilos protuberantes. ");
    vec.push_back("233. O coracao de uma crianca. ");
    vec.push_back("234. Filhotes de cachorro. ");
    vec.push_back("235. Acordar semi-nu num estacionamento a ceu aberto. ");
    vec.push_back("236. Dental dams. ");
    vec.push_back("237. A vagina da Toni Morrison. ");
    vec.push_back("238. Perineo. ");
    vec.push_back("239. Escuta ativa. ");
    vec.push_back("240. Limpeza etnica. ");
    vec.push_back("241. Comer, rezar, amar. ");
    vec.push_back("242. A mao invisivel. ");
    vec.push_back("243. Esperando ate o casamento. ");
    vec.push_back("244. Estupidez incomensuravel. ");
    vec.push_back("245. Euphoria, por Calvin Klein. ");
    vec.push_back("246. Repassar o presente. ");
    vec.push_back("247. Auto-canibalismo. ");
    vec.push_back("248. Disfuncao eretil. ");
    vec.push_back("249. Minha colecao de brinquedos sexuais eletronicos. ");
    vec.push_back("250. Brancos. ");
    vec.push_back("251. Pornografia envolvendo tentaculos. ");
    vec.push_back("252. Gel de cabelo em excesso. ");
    vec.push_back("253. Seppuku. ");
    vec.push_back("254. Dancar no gelo com parceiro do mesmo sexo. ");
    vec.push_back("255. Trapacear na olimpiada para-olimpica. ");
    vec.push_back("256. Carisma. ");
    vec.push_back("257. Keanu Reeves. ");
    vec.push_back("258. Sean Penn. ");
    vec.push_back("259. Nickelback. ");
    vec.push_back("260. Uma inspecao. ");
    vec.push_back("261. Distribuir camisinhas em porta de igreja. ");
    vec.push_back("262. Menstruacao. ");
    vec.push_back("263. Criancas com cancer anal. ");
    vec.push_back("264. Uma surpresa desagradavel. ");
    vec.push_back("265. O sul. ");
    vec.push_back("266. Violacao dos mais basicos de nossos direitos humanos. ");
    vec.push_back("267. PEDE PRA SAIR!.");
    vec.push_back("268. Ser fabuloso. ");
    vec.push_back("269. Necrofilia. ");
    vec.push_back("270. Centauros. ");
    vec.push_back("271. Os cientistas desocupados da Australia. ");
    vec.push_back("272. Cavalheirismo. ");
    vec.push_back("273. Quentinha. ");
    vec.push_back("274. Vadias. ");
    vec.push_back("275. Retardados. ");
    vec.push_back("276. orfaos. ");
    vec.push_back("277. MechaHitler. ");
    vec.push_back("278. Evacuacao dolorosa. ");
    vec.push_back("279. Outro maltido filme sobre vampiros. ");
    vec.push_back("280. Mola maluca. ");
    vec.push_back("281. O verdadeiro significado do Natal. ");
    vec.push_back("282. Estrogenio. ");
    vec.push_back("283. Indigestao de torresmo. ");
    vec.push_back("284. Aquele negocio que eletrocuta o abdomen. ");
    vec.push_back("285. Calculo renal. ");
    vec.push_back("286. Clareamento anal. ");
    vec.push_back("287. Michael Jackson. ");
    vec.push_back("288. Melhoramentos ciberneticos. ");
    vec.push_back("289. Caras que nao telefonam. ");
    vec.push_back("290. Lencois infectados com variola. ");
    vec.push_back("291. Masturbacao. ");
    vec.push_back("292. Conotacões classistas. ");
    vec.push_back("293. Emitir flatos vaginais. ");
    vec.push_back("294. Esconder uma erecao. ");
    vec.push_back("295. Lingerie comestivel. ");
    vec.push_back("296. Viagra€O,. ");
    vec.push_back("297. Sopa muito quente.  ");
    vec.push_back("298. Sexo surpresa! ");
    vec.push_back("299. X-Tudao. ");
    vec.push_back("300. Beber sozinho. ");
    vec.push_back("301. Mao furada. ");
    vec.push_back("302. Multiplas facadas. ");
    vec.push_back("303. Sujar-se. ");
    vec.push_back("304. Abuso infantil. ");
    vec.push_back("305. Cordao anal com nodulos e alca de seguranca. ");
    vec.push_back("306. Vitimas civis. ");
    vec.push_back("307. Coito interrompido. ");
    vec.push_back("308. Robert Downey, Jr. ");
    vec.push_back("309. Carne de cavalo. ");
    vec.push_back("310. Um chapeu super transado. ");
    vec.push_back("311. Kim Jongr-il. ");
    vec.push_back("312. Um pelo pubiano. ");
    vec.push_back("313. Fraternidades judias. ");
    vec.push_back("314. Cotas raciais. ");
    vec.push_back("315. Fazer aquilo na bunda. ");
    vec.push_back("316. Alimentar Rosie O'Donnell. ");
    vec.push_back("317. Ensinar um robo a amar. ");
    vec.push_back("318. Ser foda. ");
    vec.push_back("319. Um moinho de vento cheio de cadaveres. ");
    vec.push_back("320. Toddynho. ");
    vec.push_back("321. Vestir roupa intima ao avesso pra economizar uma lavada. ");
    vec.push_back("322. Um raio da morte. ");
    vec.push_back("323. Teto de vidro. ");
    vec.push_back("324. Um congelador cheio de orgaos. ");
    vec.push_back("325. O Sonho Americano. ");
    vec.push_back("326. Barriga de chopp. ");
    vec.push_back("327. Quando voce peida e sai mais do que devia. ");
    vec.push_back("328. Pegar de volta o que foi dado. ");
    vec.push_back("329. Bebes mortos. ");
    vec.push_back("330. Prepucio. ");
    vec.push_back("331. Solos de saxofone. ");
    vec.push_back("332. Italianos. ");
    vec.push_back("333. Um feto. ");
    vec.push_back("334. Disparar uma espingarda para o alto enquanto trepa com uma cabra que esta aos berros. ");
    vec.push_back("335. Dick Cheney. ");
    vec.push_back("336. Amputados. ");
    vec.push_back("337. Eugenia. ");
    vec.push_back("338. O status de minha relacao. ");
    vec.push_back("339. Christopher Walken. ");
    vec.push_back("340. Abelhas?. ");
    vec.push_back("341. Erotismo baseado em Harry Potter. ");
    vec.push_back("342. Faculdade. ");
    vec.push_back("343. Ficar bebado ao bochechar anti-septico bucal. ");
    vec.push_back("344. Nazistas. ");
    vec.push_back("345. 200 gramas de doce heroina preta Mexicana. ");
    vec.push_back("346. Stephen Hawking dizendo coisas obscenas. ");
    vec.push_back("347. Pais mortos. ");
    vec.push_back("348. Permanencia do objeto. ");
    vec.push_back("349. Polegares opositores. ");
    vec.push_back("350. Questões racistas em vestibular. ");
    vec.push_back("351. Falar abobrinha. ");
    vec.push_back("352. Motosserras. ");
    vec.push_back("353. Nicolas Cage. ");
    vec.push_back("354. Concursos de beleza para criancas. ");
    vec.push_back("355. Explosões. ");
    vec.push_back("356. Cheirar cola. ");
    vec.push_back("357. Repressao. ");
    vec.push_back("358. Boa Noite, Cinderela. ");
    vec.push_back("359. Minha vagina. ");
    vec.push_back("360. Biquine fio-dental. ");
    vec.push_back("361. Chacina. ");
    vec.push_back("362. Dar-se 110%. ");
    vec.push_back("363. Sua Alteza Real, Rainha Elizabeth Il. ");
    vec.push_back("364. O Caminho de Santiago. ");
    vec.push_back("365. Ser marginalizado. ");
    vec.push_back("366. Goblins. ");
    vec.push_back("367. Esperanca. ");
    vec.push_back("368. O reverendo Dr. Martin Luther ");
    vec.push_back("369. King, Jr. ");
    vec.push_back("370. Um micro-penis. ");
    vec.push_back("371. Minha alma. ");
    vec.push_back("372. Uma desolacao. ");
    vec.push_back("373. Vikings. ");
    vec.push_back("374. Gostosas. ");
    vec.push_back("375. Seducao. ");
    vec.push_back("376. Complexo de Edipo. ");
    vec.push_back("377. Gansos. ");
    vec.push_back("378. Aquecimento global. ");
    vec.push_back("379. Musica New Age. ");
    vec.push_back("380. Hot PocketsQO,. ");
    vec.push_back("381. Fazer beicinho. ");
    vec.push_back("382. Homicidio em direcao veicular. ");
    vec.push_back("383. Sufragio feminino. ");
    vec.push_back("384. Um preservativo defeituoso. ");
    vec.push_back("385. Sessao da Tarde. ");
    vec.push_back("386. Criancas africanas. ");
    vec.push_back("387. O massacre no Virginia Tech. ");
    vec.push_back("388. Barack Obama. ");
    vec.push_back("389. Asiaticos que nao sao bons em matematica. ");
    vec.push_back("390. Homens japoneses idosos. ");
    vec.push_back("391. Troca de gentilezas. ");
    vec.push_back("392. Heteronormatividade. ");
    vec.push_back("393. Separar o Mar Vermelho. ");
    vec.push_back("394. Arnold Schwarzenegger. ");
    vec.push_back("395. Sexo oral na direcao. ");
    vec.push_back("396. Barriga tanquinho. ");
    vec.push_back("397. Pao na chapa. ");
    vec.push_back("398. Um leao de zoologico deprimido. ");
    vec.push_back("399. Um saco de feijões magicos. ");
    vec.push_back("400. Mas decisões ao longo da vida. ");
    vec.push_back("401. Minha vida sexual. ");
    vec.push_back("402. Auschwitz. ");
    vec.push_back("403. Uma tartaruga- mordedora mordiscando a ponta do seu penis. ");
    vec.push_back("404. Uma detonacao termonucilear. ");
    vec.push_back("405. O clitoris. ");
    vec.push_back("406. O Big Bang. ");
    vec.push_back("407. Minas terrestres. ");
    vec.push_back("408. Amigos que comem todo o lanche. ");
    vec.push_back("409. Cabras comendo latas. ");
    vec.push_back("410. A Danca da Fada Acucarada. ");
    vec.push_back("411. Masturbar-se em uma poca de lagrimas de criancas. ");
    vec.push_back("412. Carne humana. ");
    vec.push_back("413. Tempo pra mim. ");
    vec.push_back("414. Tuneis clandestinos. ");
    vec.push_back("415. Piadas inoportunas sobre o holocausto. ");
    vec.push_back("416. Um mar de problemas. ");
    vec.push_back("417. Historias de lenhador. ");
    vec.push_back("418. A voz do Morgan Freeman. ");
    vec.push_back("419. Mulheres em comerciais de yogurte. ");
    vec.push_back("420. Aumento peniano natural. ");
    vec.push_back("421. Ser um feiticeiro filho-da-puta. ");
    vec.push_back("422. Piercings genitais. ");
    vec.push_back("423. Travestis que nao parecem. ");
    vec.push_back("424. Brigas de travesseiro sensuais. ");
    vec.push_back("425. Bolas. ");
    vec.push_back("426. Vovo. ");
    vec.push_back("427. Friccao. ");
    vec.push_back("428. Estraga-festa. ");
    vec.push_back("429. Peidar e se mandar. ");
    vec.push_back("430. Ser chato com criancas. ");
    vec.push_back("431. Colocar armadilhas em casa pra pegar assaltantes. ");
    vec.push_back("432. Trepar. ");
    vec.push_back("433. Morrer. ");
    vec.push_back("434. Furacao Katrina. ");
    vec.push_back("435. Gays. ");
    vec.push_back("436. A loucura do homem. ");
    vec.push_back("437. Homens. ");
    vec.push_back("438. Os amish. ");
    vec.push_back("439. Ovos de pterodacitilo. ");
    vec.push_back("440. Dinamica de grupo. ");
    vec.push_back("441. Um tumor cerebral. ");
    vec.push_back("442. Ter medo de si proprio. ");
    vec.push_back("443. Lady Gaga. ");
    vec.push_back("444. O entregador de leite. ");
    vec.push_back("445. Dizer o que pensa.");  
}

/*
000. Frase zero
001. Frase um
002. Frase dois
003. Frase tres
004. Frase quatro
005. Frase cinco
006. Frase seis
007. Frase sete
008. Frase oito
009. Frase nove
010. Frase dez
*/