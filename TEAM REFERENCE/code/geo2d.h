/* Geometry Library
 * 
 * Not Tested Yet!!!
 *  */
 
#define EPS 1e-12
typedef double type; 

/* Funciones Basicas y Constantes */
const type PI = acos(-1); 

/* Conversions */
inline type deg_to_rad(type deg){ return deg * PI / 180.0; }
inline type rad_to_deg(type rad){ return rad * 180.0 / PI; }

/* Sign */
int sgn(type a){ return a < -EPS ? -1 : a > EPS; }

/* Class Point-Vector */
struct pt{
    type x, y;
    
    /* Basics */
    pt(type x, type y): x(x), y(y){}
    pt operator + (const pt p){ return {x + p.x, y + p.y}; }
    pt operator - (const pt p){ return {x - p.x, y - p.y}; }
    pt operator * (type d){ return {x * d, y * d}; }
    pt operator / (type d){ return {x / d, y / d}; }
    bool operator == (const pt p)
        { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; } 
    
    /* Dot and Cross Product */
    type operator * (const pt p){ return x * p.x + y * p.y; }
    type operator ^ (const pt p){ return x * p.y - y * p.x; }
    
    /* Norma del vector */
    type norm(){ return sqrt(x * x + y * y); }
    
    /* Norma al Cuadrado del Vector */
    type norm2(){ return x * x + y * y; }
    
    /* Traslada un punto en la direcccion del vector vec */
    pt translate(pt vec){ return *this + vec; }
    
    /* Escala el punto, a un cierto ratio, alrededor de un centro c */
    pt scale(pt c, type ratio){ return c + (*this - c) * ratio; }
    
    /* Rota el punto un angulo a */
    pt rot(type a){ return {x * cos(a) - y * sin(a), x * sin(a) + y * cos(a) }; }
    
    /* Vector perpendicular */
    pt perp(){ return {-y, x};  } 
};

/* Stream Overload for points */
ostream &operator << (ostream &os, const pt &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

/* Distance between two points */
type dist(pt& a, pt& b){ return sqrt((a - b) * (a - b)); }

/* Square Distance between two points */
type dist2(pt& a, pt& b){ return (a - b) * (a - b); }

/* Angle between two vectors */
type angle(pt& a, pt& b){
    type cos = a * b / a.norm() / b.norm();
    return acos(max(-1.0, min(1.0, cos)));
}

/* Devuelve + si c esta izq(ab), - der(ab) y 0 si abc son colineares */
type orient(pt a, pt b, pt c){ return (b - a) ^ (c - a); }

/* Class Line with form v ^ (x, y) = c */    
struct line{
    /* Vector director (-b, a) */
    pt v;    
    type c;
    
    line(pt v, type c): v(v), c(c){} 
    line(type a, type b, type c): v({-b, a}), c(c){}
    line(pt a, pt b): v(b-a), c(v ^ a){}  
    
    /* Interseccion de dos lineas */
    pt operator & (line l){
        type not_parall = v ^ l.v;
           
        assert(not_parall);
        return (l.v * c - v * l.c) / not_parall;
    }
    
    /* Devuelve + si izq, 0 si esta sobre la linea y - der */ 
    type side(pt p){ return (v ^ p) - c; }
    
    /* Distancia de un punto a una recta */
    type dist(pt p){ return fabs(side(p)) / v.norm(); }
    
    /* Distancia Cuadratica de un punto a una recta */
    type dist2(pt p){ return side(p) * side(p) / (type)v.norm2(); }
    
    /* Compara dos puntos por cual aparece primero en la linea */
    bool cmp_proj(pt a, pt b){ return v * a < v * b; }
    
    /* Traslada una linea en la direccion del vector t */
    line tranlate(pt t){ return {v, c + (v * t)}; }
    
    /* Proyeccion de p sobre la recta */
    pt proj(pt p){ return p - v.perp() * side(p) / v.norm2(); }
    
    /* Reflexion de p sobre la recta */
    pt refl(pt p){ return p - v.perp() * 2 * side(p) / v.norm2(); }
};    
    
/* Stream Overload */
ostream &operator << (ostream &os, const line &l) {
    return os << l.v.y << "x + " << -l.v.x << "y = " << l.c;
}

/* Bisectriz del angulo entre dos vectores */
line bisector(line& l1, line& l2, bool interior){
    assert((l1.v ^ l2.v) != 0);
    
    type sign = interior ? 1: -1;
    return {l2.v / l2.v.norm() + l1.v / l1.v.norm() * sign,
            l2.c / l2.v.norm() + l1.c / l1.v.norm() * sign };    
}

/* 
 * Segments
 *  */

/* Cheque si un punto p esta sobre el disco de diametro [ab] */
bool in_disk(pt a, pt b, pt p){
    return (a - p) * (b - p) <= 0; 
}

bool on_segment(pt a, pt b, pt p){
    return orient(a, b, p) == 0 && in_disk(a, b, p); 
}

/* 
 * Polygons 
 * */

/* Tests if a polygon is convex */
bool is_convex(vector<pt>& P){
   bool has_pos = false, has_neg = false;
   
   for(int i=0, n = P.size(); i < n; i++){
       int o = orient(P[i], P[(i+1)%n], P[(i+2)%n]);
       if( o > 0 ) has_pos = true;   
       if( o < 0 ) has_neg = true;   
   } 
   
   return !(has_pos && has_neg);    
}

/* Area de un Triangulo */
type area_triangle(pt a, pt b, pt c){
    return fabs((b-a) ^ (c-a)) / 2.0;    
}

/* Area del Poligono */
type area_poligon(vector<pt>& P){
    type ans = 0.0;
    
    for(int i=0, n = P.size(); i < n; i++)
        ans += P[i] ^ P[(i+1)%n];
    return fabs(ans) / 2.0;
}

/* Checks if [pq] crosses ray from a */
bool crosses_ray(pt a, pt p, pt q){
    return ((q.y >= a.y) - (p.y >= a.y)) * orient(a, p, q) > 0;    
}

/* Tests if a point is inside of a polygon */
bool in_polygon(vector<pt>& P, pt a, bool strict = true){
    int ans = 0;
    
    for(int i=0, n = P.size(); i < n; i++){
        if( on_segment(P[i], P[(i+1)%n], a) )
            return !strict;
        ans += crosses_ray(a, P[i], P[(i+1)%n]);    
    }
    return ans & 1;
}

/*
 * Points Groups
 **/
 
/* Ordena los puntos por su angulo, desde (-PI, PI] */
void polar_sort(vector<pt>& P, pt o = {0, 0}){
    sort(all(P), [o](pt a, pt b){
        a = a - o, b = b - o;
        assert((a.x != 0 || a.y != 0) && (b.x != 0 || b.y != 0));    
        
        bool as = a.y > 0 || (a.y == 0 && a.x < 0);
        bool bs = b.y > 0 || (b.y == 0 && b.x < 0);
        
        return as == bs ? 0 < (a ^ b) : as < bs;
    });    
}

/* Cicles
 * 
 * */

/* Class Circle-Circunference */
struct circle{
    pt o;
    type r;
    
    /* Constructores Basicos */
    circle(pt o, type r): o(o), r(r){}
    
    /* Constructor dados tre puntos no colineales */
    circle(pt a, pt b, pt c): o(0, 0){
        b = b - a, c = c - a;
        
        assert( fabs(b ^ c) > EPS );    
        
        o = a + (b * c.norm2() - c * b.norm2()) / (b ^ c) / 2;
        r = dist(o, a);
    }
    
    /* Longitud de la Circunferencia */
    type length(){ return 2.0 * PI * r; }
    
    /* Intersecciones con una recta */
    vector<pt> operator & (line l){
        vector<pt> ans;
        
        type h2 = r*r - l.dist2(o);
        
        if( h2 > -EPS ){
            pt p = l.proj(o);
            pt h = l.v * sqrt(h2) / l.v.norm();
            
            ans.push_back(p + h);
            if( h2 > EPS ) ans.push_back(p - h);    
        }
        return ans;
    }
}; 
