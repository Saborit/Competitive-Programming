����D��و7��|��W\ʃ3+y��;c�D)]"N�P��*��P�$X��$�d��Oy����u����y���f�U:������.�2� �:�ŉJ��a�r ��oy|��x�jpG�b�R���	���e^{x��������z vvKi�.c��ݺ��#�1��)���Bֻ4-X����i��¡�`F��Cc��̥�V�u���L��#ه�f�4����t�6�!$/r���]����d1t4��|r�*L�Ń)��ZW�JJ����������?Ӣ.�\GXz%����M�y2����5��MD�ϱ�3u�m>�1<s��owm�@ⶹ	�8@kCR�>Alh���*C���N���P�R Cj31�*Mn��n!8���4֗A�*\����� �ǳx���+��Ϟ��'�4��Qw�X�\���Mb ��y��l_.D(*��n�{4�׋��*���4"5��J���ɚ��w�W\"!d�"�o���rz8�FQ@in", "r", stdin);
     //freopen("nearcows.out", "w", stdout);

     scanf("%d%d", &cn, &k);
     for(int i=1; i < cn; i++){
         scanf("%d%d", &a, &b);
         G[a].push_back(b);
         G[b].push_back(a);
     }
     for(int i=1; i<=cn; i++){
         scanf("%d", &A[i]);
         H[i][0] = A[i];
     }

     for(id = 1; id<=k; id++){
         fill(mk, mk+cn+1, 0);
         dfs_graph(1);
     }
     for(int i=1; i<=cn; i++)
         for(int j=1; j<=k; j++)
             H[i][j]+=H[i][j-1];


     for(int i=1; i<=cn; i++){
         nod = i;

         best = H[i][k];

         for(int j=1; j<=k && P[nod]; j++){
             last_father = nod;
             nod = P[nod];

             if(k-j>=0){
                best += H[nod][k-j];
             }
             if(k-j-1>=0){
                best -= H[last_father][k-j-1];
             }
         }
         printf("%d\n", best);
     }



 return 0;
 }

