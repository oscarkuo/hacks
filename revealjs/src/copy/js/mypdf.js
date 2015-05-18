var link = document.createElement( 'link' );
link.rel = 'stylesheet';
link.type = 'text/css';
link.href = window.location.search.match( /print-pdf/gi ) ? 'css/pdf.css' : 'css/paper.css';
document.getElementsByTagName( 'head' )[0].appendChild( link );
