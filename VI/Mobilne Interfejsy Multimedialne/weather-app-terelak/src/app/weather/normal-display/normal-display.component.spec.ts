import { ComponentFixture, TestBed } from '@angular/core/testing';

import { NormalDisplayComponent } from './normal-display.component';

describe('NormalDisplayComponent', () => {
  let component: NormalDisplayComponent;
  let fixture: ComponentFixture<NormalDisplayComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ NormalDisplayComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(NormalDisplayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
