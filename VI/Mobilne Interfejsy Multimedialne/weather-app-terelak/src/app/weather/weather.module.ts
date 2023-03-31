import { FormsModule } from '@angular/forms';
import { CUSTOM_ELEMENTS_SCHEMA, NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { NormalDisplayComponent } from './normal-display/normal-display.component';
import { SimpleDisplayComponent } from './simple-display/simple-display.component';
import { NbFormFieldModule, NbIconModule, NbInputModule, NbButtonModule, NbLayoutModule, NbToggleModule, NbCardModule, NbAutocompleteModule } from '@nebular/theme';
import { HttpClientModule } from '@angular/common/http';

@NgModule({
  declarations: [
    NormalDisplayComponent,
    SimpleDisplayComponent,
  ],
  imports: [
    CommonModule,
    NbInputModule,
    NbFormFieldModule,
    NbLayoutModule,
    NbToggleModule,
    NbCardModule,
    NbAutocompleteModule,
    NbIconModule,
    NbButtonModule,
    FormsModule,
    HttpClientModule,
  ],
  exports: [
    NormalDisplayComponent,
    SimpleDisplayComponent,
  ]
})
export class WeatherModule { }
