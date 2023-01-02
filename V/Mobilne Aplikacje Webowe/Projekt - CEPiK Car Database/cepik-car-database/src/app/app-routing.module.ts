import { ErrorComponent } from './pages/error/error.component';
import { HomeComponent } from './pages/home/home.component';
import { WojewodztwoComponent } from './pages/wojewodztwo/wojewodztwo.component';
import { PojazdComponent } from './pages/pojazd/pojazd.component';
import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  { path: '', component: HomeComponent },
  { path: 'pojazd', component: PojazdComponent },
  { path: 'wojewodztwo', component: WojewodztwoComponent },
  { path: '**', component: ErrorComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
